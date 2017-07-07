cmake_minimum_required(VERSION 3.2.1 FATAL_ERROR)

project(problems)
set (CMAKE_CXX_STANDARD 14)

# update these to suite your needs
list(APPEND CMAKE_MODULE_PATH "~/work/cmake-findgmock")
set(GTEST_ROOT "/opt/external")
set(GMOCK_ROOT "/opt/external")

enable_testing()
find_package(GTest REQUIRED)
find_package(GMock REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS} ${GMOCK_INCLUDE_DIRS})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")

add_executable(almost almost_sorted.cpp)
