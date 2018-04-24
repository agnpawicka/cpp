cmake_minimum_required(VERSION 3.8)
project(cpp)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES   wymierne/wymierna.cpp wymierne/wymierna.hpp wymierne/main.cpp wymierne/wyjatek_wymierny.hpp)
add_executable(cpp ${SOURCE_FILES})