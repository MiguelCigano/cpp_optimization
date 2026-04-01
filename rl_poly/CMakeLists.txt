cmake_minimum_required(VERSION 3.10)
project(rl_poly)

set(CMAKE_CXX_STANDARD 17)

include_directories(inc)

add_executable(rl_poly
    src/main.cpp
    src/rl_poly.cpp
    src/dynamics.cpp
    src/utils.cpp
)

