cmake_minimum_required(VERSION 3.16)
project(aoc_2025)
set(CMAKE_CXX_STANDARD 17)

add_library(common STATIC file.cpp file.h
        trim.cpp
        trim.h
)

add_subdirectory(day1)
add_subdirectory(day2)
