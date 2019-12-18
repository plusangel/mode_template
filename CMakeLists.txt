cmake_minimum_required(VERSION 3.15)
project(6_non_type)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fconcepts")

include_directories(
        include
        ${gtest_SOURCE_DIR}/include
        ${gtest_SOURCE_DIR}
)

add_subdirectory(lib)
enable_testing()

add_executable(temp_exp main.cpp)

add_executable(modeUnitTests tests/mode_tests.cpp)
target_link_libraries(modeUnitTests gtest gtest_main)
add_test(modeUnitTests modeUnitTests)