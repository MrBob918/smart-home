cmake_minimum_required(VERSION 4.0 FATAL_ERROR)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)


include(FetchContent)

project(smart_house)

add_executable(Handler)
target_sources(Handler PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp)

find_package(Boost REQUIRED beast)

if(NOT Boost_FOUND)
    message("dosn't find required components or all boost. Try install manual")
    
    FetchContent(
        NAME Boost
        GIT_REPOSITORY https://github.com/boostorg/boost.git
        GIT_TAG 1.90.0
    )
    FetchContent_MakeAvailable(Boost)
    
    target_link_libraries(Handler PRIVATE Boost:beast)

elseif(Boost_FOUND)
    massege("all required boost components was find")
    
    target_link_libraries(Handler PRIVATE Boost:beast)

else()
    message(unknown error!)
endif()
