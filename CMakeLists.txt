cmake_minimum_required(VERSION 4.0 FATAL_ERROR)
project(smart_house)

#include(FetchContent)

add_executable(Handler)

#FetchContent_Declare(CPM GIT_REPOSITORY https://github.com/cpm-cmake/CPM.cmake.git GIT_TAG v0.42.1 )
#FetchContent_MakeAvailable(CPM)

#CPMAddPackage(NAME boost GITHUB_REPOSITORY boostorg/boost GIT_TAG boost-1.90.0 )
#AddBoost(COMPONENTS beast)

target_sources(Handler PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp)

#target_link_libraries(Handler PRIVATE Boost::beast)