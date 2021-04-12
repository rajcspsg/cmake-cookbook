cmake_minimum_required(VERSION 3.19 FATAL_ERROR)

project(receipe-chapter-04-01 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(sum_integers sum_integers.hpp sum_integers.cpp)

add_executable(main main.cpp)
target_link_libraries(main sum_integers)

add_executable(sum_test catch_sum_test.cpp)
target_link_libraries(sum_test sum_integers)

enable_testing()

add_test(NAME cpp_test COMMAND $<TARGET_FILE:sum_test>)


add_test(NAME catch_test COMMAND $<TARGET_FILE:sum_test> --success)


