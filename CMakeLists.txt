cmake_minimum_required(VERSION 3.8)
project(cpp)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES   bst/bst.cpp bst/bst.hpp bst/main.cpp)
add_executable(cpp ${SOURCE_FILES})