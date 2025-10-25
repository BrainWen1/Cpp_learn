#!/bin/bash

# 检查参数是否传入程序名
if [ $# -ne 1 ]; then
    printf "Tip: run <file name>\nexample: run main.\n"
    exit 1
fi

target=$1
bin_dir=$(pwd)

# 检查是否在 bin 目录下
if [ "$(basename "$bin_dir")" != "bin" ]; then
    printf "Error: Please step into bin/.\n"
    exit 1
fi

chapter_dir=$(dirname "$bin_dir")

# 检查 CMakeLists.txt 是否存在
cmake_file="${chapter_dir}/CMakeLists.txt"

if [ ! -f "$cmake_file" ]; then
    echo "Error: CMakeLists.txt not found：(path: $cmake_file).\n"
    exit 1
fi

# 运行 cmake 生成 Makefile
echo "========== cmake build... ========="
cmake "$chapter_dir"  # 等价于 cmake ..

# 检查 cmake 是否成功
if [ $? -ne 0 ]; then
    echo "Error: cmake build failedly, please check out your CMakeLists.txt.\n"
    exit 1
fi

# 运行 make 编译目标程序
echo -e "\n========== make compiling $target... =========="
make "$target"  # 只编译指定目标（比直接 make 更快）

# 检查 make 是否成功
if [ $? -ne 0 ]; then
    echo "Error: make compiled $target failedly, please check out your code or CMakeLists.txt.\n"
    exit 1
fi

# 运行可执行文件
echo -e "\n========== running $target... =========="
./"$target"  # 可执行文件在 bin 目录下，直接运行
