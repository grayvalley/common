cmake_minimum_required(VERSION 3.16)

set(CMAKE_CXX_STANDARD 17)

add_executable(test_main test_main.cpp)

target_link_libraries(test_main gtest gtest_main)
target_link_libraries(test_main pthread)
target_link_libraries(test_main common)

