cmake_minimum_required(VERSION 3.10)
project(learn)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)

add_executable(test 2_6HEADER/test.cpp)

target_include_directories(test PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/2_6HEADER)