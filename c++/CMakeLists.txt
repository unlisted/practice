cmake_minimum_required(VERSION 3.5.1 FATAL_ERROR)

project(prep)
set (CMAKE_CXX_STANDARD 14)

add_executable(split split.cpp)
add_executable(reverse reverse.cpp)
add_executable(recursion1 recursion1.cpp)
add_executable(recursion2 recursion2.cpp)
add_executable(bin_search bin_search.cpp)
add_executable(bsort bsort.cpp)
add_executable(isort isort.cpp)
