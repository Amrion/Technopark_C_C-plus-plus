cmake_minimum_required(VERSION 3.5.1)
project(project C CXX)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_FLAGS "-g -O0 -Wall -fprofile-arcs -ftest-coverage -fPIC")
set(CMAKE_CXX_OUTPUT_EXTENSION_REPLACE 1)
set(CMAKE_C_FLAGS "-g -O0 -Wall -fprofile-arcs -ftest-coverage -fPIC")
set(CMAKE_C_OUTPUT_EXTENSION_REPLACE 1)

set(LIB_SOURCE_FILES src/parser_url.c)
add_library(main STATIC ${LIB_SOURCE_FILES})

add_executable(project src/main.c src/parser_url.c src/print.c)
target_link_libraries(project main m -fprofile-arcs -ftest-coverage -fPIC)

enable_testing()
find_package(GTest REQUIRED)
find_package(Threads)

include_directories(${GTEST_INCLUDE_DIRS})
add_executable(gtest src/gtest.cpp)
target_link_libraries(gtest ${GTEST_LIBRARIES} pthread main)