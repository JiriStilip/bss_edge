#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <cstring>

#include <cstdint>

#include <cpr/cpr.h>
#include <nlohmann/json.hpp>

#include <chrono>
#include <ctime>
#include <iomanip>
#include <sstream>


void parse_data(const char* buffer, std::int32_t& temperature, std::int32_t& humidity) {
    
    std::int32_t* tempPtr = reinterpret_cast<std::int32_t*>(const_cast<char*>(buffer));
    temperature = *tempPtr;

    std::int32_t* humPtr = reinterpret_cast<std::int32_t*>(const_cast<char*>(buffer + sizeof(std::int32_t)));
    humidity = *humPtr;
}

std::string get_current_timestamp() {
    auto now = std::chrono::system_clock::now();
    auto now_c = std::chrono::system_clock::to_time_t(now);
    std::stringstream ss;
    ss << std::put_time(std::localtime(&now_c), "%Y-%m-%d %H:%M:%S");
    return ss.str();
}

std::string get_json_rpc_temperature(std::int32_t temperature) {
    nlohmann::json j;
    nlohmann::json data = nlohmann::json::array();

    data.push_back({
        {"time", get_current_timestamp()},
        {"temperature", temperature},
        {"quality", 100} // TODO resit nejak kvalitu?
    });

    j["jsonrpc"] = "2.0";
    j["id"] = "1";
    j["method"] = "insertData";
    j["params"]["apiKey"] = "JUJIQNFVRHGVMNHYCYRZ6HBO4"; // TODO jakej spravne API key?
    j["params"]["secretKey"] = "B0AMCI2YWT1H83X8I3H7U1O5H"; // TODO dtto secret key?
    j["params"]["objectTableId"] = 1; // TODO nastavovat podle odkud data prijdou, zatim testovaci pole
    j["params"]["objectId"] = 16; // TODO dtto
    j["params"]["ignoreDuplicit"] = true;
    j["params"]["data"] = data;

    return j.dump();
}

std::string get_json_rpc_humidity(std::int32_t humidity) {
    nlohmann::json j;
    nlohmann::json data = nlohmann::json::array();

    data.push_back({
        {"time", get_current_timestamp()},
        {"humidity", humidity},
        {"quality", 100} // TODO resit nejak kvalitu?
    });

    j["jsonrpc"] = "2.0";
    j["id"] = "1";
    j["method"] = "insertData";
    j["params"]["apiKey"] = "JUJIQNFVRHGVMNHYCYRZ6HBO4"; // TODO jakej spravne API key?
    j["params"]["secretKey"] = "B0AMCI2YWT1H83X8I3H7U1O5H"; // TODO dtto secret key?
    j["params"]["objectTableId"] = 1; // TODO nastavovat podle odkud data prijdou, zatim testovaci pole
    j["params"]["objectId"] = 17; // TODO dtto
    j["params"]["ignoreDuplicit"] = true;
    j["params"]["data"] = data;
    
    return j.dump();
}

void post_request(std::string json_rpc_request) {
    auto r = cpr::Post(cpr::Url{ "https://kiv-bss.iotdata.zcu.cz/api/v0/bss_measurement" },
        cpr::Body{ json_rpc_request },
        cpr::Header{ {"Content-Type", "application/json"} });

    std::cout << "Status = " << r.status_code << std::endl;
    std::cout << "Body = " << r.text << std::endl;
}

int main() {

    int sockfd;
    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        perror("socket failed");
        return EXIT_FAILURE;
    }

    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(12345); // TODO zmenit port
    addr.sin_addr.s_addr = inet_addr("127.0.0.1"); // TODO adresa rozhrani vysilane WiFi
    memset(addr.sin_zero, 0, sizeof(addr.sin_zero));

    if ((bind(sockfd, (struct sockaddr*)&addr, sizeof(addr))) < 0) {
        perror("bind failed");
        return EXIT_FAILURE;
    }

    char buffer[1024];
    struct sockaddr_in sender_addr;
    socklen_t sender_addrlen = sizeof(sender_addr);

    while (true) {
        int num_bytes = recvfrom(sockfd, buffer, sizeof(buffer), 0, (struct sockaddr*)&sender_addr, &sender_addrlen);
        if (num_bytes < 0) {
            perror("recvfrom failed");
            break;
        }
        buffer[num_bytes] = '\0';
        std::cout << "Received " << num_bytes << " bytes from " << inet_ntoa(sender_addr.sin_addr) << ":" << ntohs(sender_addr.sin_port) << std::endl;
        
        std::cout << "Processing..." << std::endl;
        std::int32_t temperature;
        std::int32_t humidity;
        parse_data(buffer, temperature, humidity);
        std::string temperature_req = get_json_rpc_temperature(temperature);
        std::string humidity_req = get_json_rpc_humidity(humidity);

        std::cout << "Posting..." << std::endl;
        post_request(temperature_req);
        post_request(humidity_req);

        std::cout << "Done." << std::endl;

        sendto(sockfd, "OK", strlen("OK"), 0, (struct sockaddr*)&sender_addr, sender_addrlen); // TODO definovat reply zpravy
    }

    close(sockfd);
    return EXIT_SUCCESS;
}
