cmake_minimum_required(VERSION 3.20 FATAL_ERROR)
project(receipe-04-04 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)


add_library(sum_integers sum_integers.cpp)

find_package(Boost 1.75 REQUIRED COMPONENTS unit_test_framework)

# set(BOOST_ROOT "/home/rajkumar/Coding/cpp/boost_1_75_0")
#find_package(Boost CONFIG)

add_executable(cpp_test test.cpp)
target_link_libraries(cpp_test PRIVATE sum_integers Boost::unit_test_framework)

target_compile_definitions(cpp_test PRIVATE BOOST_TEST_DYN_LINK)

enable_testing()

add_test(NAME boost_test COMMAND $<TARGET_FILE:cpp_test>)


