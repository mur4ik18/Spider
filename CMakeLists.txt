cmake_minimum_required(VERSION 3.27)
project(Spider)

set(CMAKE_CXX_STANDARD 14)

include_directories(controller)

add_executable(Spider
        controller/main.cpp
        controller/ComPort.h
        controller/ComPort.cpp
)
