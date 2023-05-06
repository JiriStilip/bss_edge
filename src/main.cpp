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

#include "bss.pb.h"

#define UDP_ADDRESS "192.168.69.1"
#define UDP_PORT 8266
#define UDP_REPLY_OK "OK"
#define UDP_REPLY_ERROR "ERROR"

/**
 * @brief Vycet typu mereni pro rozliseni JSON RPC requestu
 * 
 */
enum class measurement_type {
    temperature = 1,
    humidity = 2,
    ambient_light = 3,
    // --- MISTO PRO PRIDAVANI DALSICH MERENI ---
};

/**
 * @brief Vraci aktualni datum a cas v potrebnem formatu
 * 
 * @return std::string 
 */
std::string get_current_timestamp() {
    auto now = std::chrono::system_clock::now();
    auto now_c = std::chrono::system_clock::to_time_t(now);
    std::stringstream ss;
    ss << std::put_time(std::localtime(&now_c), "%Y-%m-%d %H:%M:%S");
    return ss.str();
}

/**
 * @brief Vraci hotovu JSON RPC zpravu
 * 
 * @tparam xint32 pro rozliseni signedness
 * @param node_id id nodu
 * @param type typ daneho mereni
 * @param value hodnota daneho mereni
 * @return std::string JSON RPC retezec k odeslani
 */
template <class xint32>
std::string get_json_rpc(std::uint32_t node_id, measurement_type type, xint32 value) {
    nlohmann::json j;
    nlohmann::json data = nlohmann::json::array();

    // podle typu mereni se vyplni pole data (jediny tento postup - push_back() pole data jako celek - dava pro nase pouziti korektne uzavorkovany vystup)
    if (type == measurement_type::temperature)
        data.push_back({
            {"time", get_current_timestamp()},
            {"temperature", static_cast<double>(value/100.0)},
            {"quality", 100}
        });
    else if (type == measurement_type::humidity)
        data.push_back({
            {"time", get_current_timestamp()},
            {"humidity", value},
            {"quality", 100}
        });
    else if (type == measurement_type::ambient_light)
        data.push_back({
            {"time", get_current_timestamp()},
            {"light", value},
            {"quality", 100}
        });
    // --- MISTO PRO PRIDAVANI DALSICH MERENI ---
    else return nullptr;

    j["jsonrpc"] = "2.0";
    j["id"] = "1";
    j["method"] = "insertData";
    j["params"]["apiKey"] = "JUJIQNFVRHGVMNHYCYRZ6HBO4";
    j["params"]["secretKey"] = "B0AMCI2YWT1H83X8I3H7U1O5H";
    j["params"]["objectTableId"] = 1;
    j["params"]["objectId"] = (((node_id - 1) * 3) + static_cast<int>(type)); // je treba dodrzovat cislovani novych objektu v databazi
    j["params"]["ignoreDuplicit"] = true;
    j["params"]["data"] = data;

    return j.dump();
}

/**
 * @brief Postuje JSON RPC request na iotdata
 * 
 * @param json_rpc_request retezec requestu
 */
void post_request(std::string json_rpc_request) {
    auto r = cpr::Post(cpr::Url{ "https://kiv-bss.iotdata.zcu.cz/api/v0/bss_measurement" },
        cpr::Body{ json_rpc_request },
        cpr::Header{ {"Content-Type", "application/json"} });

    std::cout << "Status = " << r.status_code << std::endl;
    std::cout << "Body = " << r.text << std::endl;
}

/**
 * @brief Nabinduje UDP port, po prijeti a dekodovani zpravy postuje JSON RPC request na iotdata
 * 
 * @return int 
 */
int main() {

    int sockfd;
    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        perror("socket failed");
        return EXIT_FAILURE;
    }

    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(UDP_PORT);
    addr.sin_addr.s_addr = INADDR_ANY; // inet_addr(UDP_ADDRESS); // INADDR_ANY nevadi na testovani, ale konkretni adresa rozhrani je korektnejsi moznost
    memset(addr.sin_zero, 0, sizeof(addr.sin_zero));

    if ((bind(sockfd, (struct sockaddr*)&addr, sizeof(addr))) < 0) {
        perror("bind failed");
        return EXIT_FAILURE;
    }

    char buffer[1024]; // buffer pro prijimane zpravy
    struct sockaddr_in sender_addr;
    socklen_t sender_addrlen = sizeof(sender_addr);

    while (true) {
        // prijeti UDP datagramu
        int num_bytes = recvfrom(sockfd, buffer, sizeof(buffer), 0, (struct sockaddr*)&sender_addr, &sender_addrlen);
        if (num_bytes < 0) {
            perror("recvfrom failed");
            break;
        }
        buffer[num_bytes] = '\0';
        std::cout << "Received " << num_bytes << " bytes from " << inet_ntoa(sender_addr.sin_addr) << ":" << ntohs(sender_addr.sin_port) << std::endl;
        
        // parse Protobuf zpravy
        std::cout << "Processing... ";
        bss::Measurement measurement;
        if (!measurement.ParseFromArray(buffer, num_bytes)) {
            std::cout << "Failed." << std::endl;
            sendto(sockfd, UDP_REPLY_ERROR, strlen(UDP_REPLY_ERROR), 0, (struct sockaddr*)&sender_addr, sender_addrlen);
            continue;
        }
        if (measurement.node_id() == 0) {
            std::cout << "Invalid node_id." << std::endl;
            continue;
        }
        std::cout << "Done." << std::endl;

        // v pripade, ze je dana hodnota pritomna, postuje se na iotdata
        std::cout << "Posting..." << std::endl;
        if (measurement.has_temperature()) {
            std::cout << "Temperature:" << std::endl;
            post_request(get_json_rpc<int32_t>(measurement.node_id(), measurement_type::temperature, measurement.temperature()));
        }
        if (measurement.has_humidity()) {
            std::cout << "Humidity:" << std::endl;
            post_request(get_json_rpc<uint32_t>(measurement.node_id(), measurement_type::humidity, measurement.humidity()));
        }
        if (measurement.has_ambient_light()) {
            std::cout << "Ambient light:" << std::endl;
            post_request(get_json_rpc<uint32_t>(measurement.node_id(), measurement_type::ambient_light, measurement.ambient_light()));
        }
        // --- MISTO PRO PRIDAVANI DALSICH MERENI ---
        std::cout << "Done." << std::endl;

        std::cout << "Success!" << std::endl;
        sendto(sockfd, UDP_REPLY_OK, strlen(UDP_REPLY_OK), 0, (struct sockaddr*)&sender_addr, sender_addrlen);
    }

    close(sockfd);
    return EXIT_SUCCESS;
}
