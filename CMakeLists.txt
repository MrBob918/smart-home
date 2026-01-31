cmake_minimum_required(VERSION 4.0 FATAL_ERROR)
project(smart_house)

add_executable(Handler)

target_sources(Handler PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp)