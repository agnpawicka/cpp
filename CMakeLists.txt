cmake_minimum_required(VERSION 3.8)
project(cpp)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES  matrix/matrix.cpp matrix/matrix.hpp matrix/main.cpp matrix/Except.hpp)
add_executable(cpp ${SOURCE_FILES})