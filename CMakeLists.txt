# setup section
##################################################################

# version option
cmake_minimum_required(VERSION 4.2)
set(AddBoost.cmake_VERSION 3.7.3)
set(TRY_BOOST_VERSION "1.90.0")
set(CPM_VERSION v0.42.1)

# cmake options
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# CXX option
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# boost libraries
set(BOOST_HEADER_ONLY_COMPONENTS_THAT_YOU_NEED "asio;beast;uuid")
set(BOOST_NOT_HEADER_ONLY_COMPONENTS_THAT_YOU_NEED "system")

##################################################################


# project name
project(smart_house)


# download section
##################################################################

# download cpm
file(DOWNLOAD https://github.com/cpm-cmake/CPM.cmake/releases/download/${CPM_VERSION}/get_cpm.cmake ${CMAKE_CURRENT_BINARY_DIR}/cmake/CPM.cmake)
# activate get_cpm to project
include(${CMAKE_CURRENT_BINARY_DIR}/cmake/CPM.cmake)

# download AddBoost
CPMAddPackage(
  NAME AddBoost.cmake
  VERSION "${AddBoost.cmake_VERSION}"
  URL "https://github.com/Arniiiii/AddBoost.cmake/archive/refs/tags/${AddBoost.cmake_VERSION}.tar.gz"
)

###################################################################


add_boost(
  TRY_BOOST_VERSION BOOST_HEADER_ONLY_COMPONENTS_THAT_YOU_NEED
  BOOST_NOT_HEADER_ONLY_COMPONENTS_THAT_YOU_NEED
)

# create elf file
add_executable(Handler)

# link src files to elf file
target_sources(Handler PRIVATE ./main.cpp)

# link lib files to elf file
target_link_libraries(Handler PRIVATE Boost::beast)
