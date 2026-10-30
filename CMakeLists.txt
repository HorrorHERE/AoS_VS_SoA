cmake_minimum_required(VERSION 3.16)
project(aos_vs_soa LANGUAGES CXX)

set(CMAKE_CXX_STANDART 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release CACHE STRING "" FORCE)
endif()

set(CMAKE_BUILD_TYPE Release)

add_executable(aos_vs_soa src/main.cpp src/bench_rules.cpp)

target_include_directories(aos_vs_soa PRIVATE src)

target_compile_options(aos_vs_soa PRIVATE -O2 -ffast-math -Wall -Wextra -Wpedantic)
