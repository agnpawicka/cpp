cmake_minimum_required(VERSION 3.8)
project(cpp)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES  manipulatory/main.cpp manipulatory/indeks.cpp manipulatory/indeks.hpp manipulatory/ignore.cpp manipulatory/ignore.hpp manipulatory/In.cpp manipulatory/In.hpp manipulatory/Out.cpp manipulatory/Out.hpp)
add_executable(cpp ${SOURCE_FILES})