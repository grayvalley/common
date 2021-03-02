cmake_minimum_required(VERSION 3.16)

set(CMAKE_CXX_STANDARD 17)

add_executable(test_common test_common.cpp)

target_link_libraries(test_common gtest gtest_main)
target_link_libraries(test_common pthread)
target_link_libraries(test_common common)

