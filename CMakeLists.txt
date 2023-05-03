CMAKE_MINIMUM_REQUIRED(VERSION 3.0)

PROJECT(bss)

SET(CMAKE_CXX_STANDARD 17)

include(FetchContent)
FetchContent_Declare(cpr GIT_REPOSITORY https://github.com/libcpr/cpr.git
                         GIT_TAG 0817715923c9705e68994eb52ef9df3f6845beba)
FetchContent_MakeAvailable(cpr)

FetchContent_Declare(json URL https://github.com/nlohmann/json/releases/download/v3.11.2/json.tar.xz)
FetchContent_MakeAvailable(json)

ADD_EXECUTABLE(bss_edge src/main.cpp)

target_link_libraries(bss_edge PRIVATE cpr::cpr nlohmann_json::nlohmann_json)