cmake_minimum_required(VERSION 3.10)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)

add_executable(4_8 4_8.cpp)

# 指定私有头文件
# target_include_directories(test PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/2_6HEADER)