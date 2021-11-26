cmake_minimum_required(VERSION 3.18.4)
project(dens-asio)

set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_CXX_STANDARD 20)

add_subdirectory(core)

include_directories(core)

add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(${PROJECT_NAME} boost_system boost_thread pthread core)
