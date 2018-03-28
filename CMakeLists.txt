cmake_minimum_required(VERSION 3.8)
project(cpp)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES  daty-i-czas/main.cpp daty-i-czas/Data.cpp daty-i-czas/Data.hpp daty-i-czas/dataGodz.cpp daty-i-czas/dataGodz.hpp daty-i-czas/wydarzenie.cpp daty-i-czas/wydarzenie.hpp)
add_executable(cpp ${SOURCE_FILES})