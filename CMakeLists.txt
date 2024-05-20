cmake_minimum_required(VERSION 3.28)
project(CodeCounter)

set(CMAKE_CXX_STANDARD 20)

add_executable(CodeCounter main.cpp
        include/CodeCounter.h)
include_directories(include)