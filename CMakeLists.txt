cmake_minimum_required(VERSION 3.21)
project(DateConverter)

set(CMAKE_CXX_STANDARD 23)

add_executable(DateConverter main.cpp Date.cpp Date.h DateConverter.cpp DateConverter.h)
