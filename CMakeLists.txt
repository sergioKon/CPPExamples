cmake_minimum_required(VERSION 3.28.3)
project(STL-Examples)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

#add_compile_options("$<$<COMPILE_LANGUAGE:CXX>:-Ofast;-std=c++23; -Werror=terminate -v>")

set(CMAKE_CXX_FLAGS "-std=c++23   -Werror ")
message(STATUS "CMAKE_CXX_FLAGS: ${CMAKE_CXX_FLAGS}")

add_executable(STL-Examples main.cpp helper/BigInteger.cpp helper/BigInteger.h
               TEST test/fiboTest.cpp
)





