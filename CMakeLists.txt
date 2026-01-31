cmake_minimum_required(VERSION 4.2)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

project(smart_house)

file(DOWNLOAD https://github.com/cpm-cmake/CPM.cmake/releases/latest/download/get_cpm.cmake ${CMAKE_CURRENT_BINARY_DIR}/cmake/CPM.cmake)

include(${CMAKE_CURRENT_BINARY_DIR}/cmake/CPM.cmake)


CPMAddPackage("gh:nlohmann/json@3.12.0")

add_executable(Handler)
target_sources(Handler PRIVATE ./main.cpp)

target_link_libraries(Handler nlohmann_json::nlohmann_json)
