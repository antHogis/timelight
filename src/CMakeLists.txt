# Probably doesn't need to be this recent but it's what I use
cmake_minimum_required(VERSION 3.10)

project(TimeLight LANGUAGES CXX VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_compile_definitions(PROJECT_VERSION="${CMAKE_PROJECT_VERSION}")
add_executable(TimeLight main.cpp)

