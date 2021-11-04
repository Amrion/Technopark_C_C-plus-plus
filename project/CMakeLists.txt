cmake_minimum_required(VERSION 3.14.7)
project(project C CXX)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 11)

set(CMAKE_C_FLAGS "-g -O0 -Wall -Werror  -fprofile-arcs -ftest-coverage -fPIC")
set(CMAKE_CXX_FLAGS "-g -O0 -Wall -Werror -fprofile-arcs -ftest-coverage -fPIC")



include_directories(include)

set(FIND_CONSISTENT_LIB  ${PROJECT_SOURCE_DIR}/include/main.h src_consistent/consistent.c)
add_library(find_consistent_lib STATIC ${FIND_CONSISTENT_LIB})
target_include_directories(find_consistent_lib PUBLIC ${PROJECT_SOURCE_DIR}/include)

set(FIND_PARALLEL_LIB  ${PROJECT_SOURCE_DIR}/include/main.h src_parallel/parallel.c)
add_library(find_parallel_lib SHARED ${FIND_PARALLEL_LIB})
target_include_directories(find_parallel_lib PUBLIC ${PROJECT_SOURCE_DIR}/include)

add_executable(project src/main.c  src/stopwatch.c)

target_link_libraries(project PRIVATE find_consistent_lib)
target_link_libraries(project PRIVATE find_parallel_lib -ldl)

enable_testing()
find_package(GTest REQUIRED)
find_package(Threads)

include_directories(${GTEST_INCLUDE_DIRS})

add_executable(gtest tests/timer_gtest.cpp src/stopwatch.c tests/find_gtests.cpp tests/main.cpp)
target_link_libraries(gtest ${GTEST_LIBRARIES} pthread find_consistent_lib find_parallel_lib -ldl)


