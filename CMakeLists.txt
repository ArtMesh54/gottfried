cmake_minimum_required(VERSION 3.11)
project(gottfried VERSION 0.1.0)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(gottfried main.cpp calculator.h calculator.cpp)

