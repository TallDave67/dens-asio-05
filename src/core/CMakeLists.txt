cmake_minimum_required(VERSION 3.18.4)
project(core)

# Generate the static library from the sources
add_library(core STATIC session.cpp server.cpp)

