cmake_minimum_required(VERSION 3.2.1 FATAL_ERROR)

project(prep)
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

add_executable(split split.cpp)
add_executable(reverse reverse.cpp)
add_executable(recursion1 recursion1.cpp)
add_executable(recursion2 recursion2.cpp)
add_executable(bin_search bin_search.cpp)
add_executable(bsort bsort.cpp)

add_executable(isort isort.cpp)
target_link_libraries(isort ${GTEST_BOTH_LIBRARIES})

add_executable(ssort ssort.cpp)
target_link_libraries(ssort ${GTEST_BOTH_LIBRARIES})

add_executable(qsort qsort.cpp)
target_link_libraries(qsort ${GTEST_BOTH_LIBRARIES})

add_executable(msort msort.cpp)
target_link_libraries(msort ${GTEST_BOTH_LIBRARIES})
