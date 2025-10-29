#!/bin/bash

# 定义颜色变量
RED="\033[31m"      # 红色
GREEN="\033[32m"    # 绿色
YELLOW="\033[33m"   # 黄色
PURPLE="\033[35m"   # 紫色
RESET="\033[0m"     # 重置颜色

# 检查参数是否传入程序名
if [ $# -ne 1 ]; then
    printf "${RED}Tip: run <file name>\nexample: run main.${RESET}\n"
    exit 1
fi

target=$1
bin_dir=$(pwd)
chapter_dir=$(dirname "$bin_dir")
root_dir=$(dirname "$chapter_dir")  # chapter_dir 是 chapter_10，dirname 取它的父目录（根目录）
build_dir="${root_dir}/build"
cmake_file="${chapter_dir}/CMakeLists.txt"

# 检查是否在 bin 目录下
if [ "$(basename "$bin_dir")" != "bin" ]; then
    printf "${RED}Error: Please step into bin directory.${RESET}\n"
    exit 1
fi

if [ ! -f "$cmake_file" ]; then
    printf "${RED}Error: CMakeLists.txt not found：(path: %s).${RESET}\n" "$cmake_file"
    exit 1
fi

# 自动创建根目录的 build 目录（如果不存在，避免首次执行报错）
mkdir -p "$build_dir"

# 运行 cmake 生成 Makefile
printf "${PURPLE}============= cmake building... =================${RESET}\n"

# 让 CMake 从根目录启动，指定构建目录为根目录下的build目录（-B 选项）
# 【可选静默】取消下一行注释，可减少 CMake 输出（仅显示错误）
cmake -S "$root_dir" -B "$build_dir" -DCMAKE_VERBOSE_MAKEFILE=OFF --log-level=ERROR
# cmake -S "$root_dir" -B "$build_dir"

# 检查 cmake 是否成功
if [ $? -ne 0 ]; then
    printf "${RED}Error: cmake build failed, please check out your CMakeLists.txt.${RESET}\n"
    exit 1
fi

# 运行 make 编译目标程序
printf "${PURPLE}============= make compiling %s... ============${RESET}\n" "$target"

# -C 表示进入build目录执行make
# 【可选静默】取消下一行注释，可让 make 仅输出错误（适合追求极简输出）
make -C "$build_dir" "$target" -s
# make -C "$build_dir" "$target"

# 检查 make 是否成功
if [ $? -ne 0 ]; then
    printf "${RED}Error: make compiled %s failed, please check out your code or CMakeLists.txt.${RESET}\n" "$target"
    exit 1
fi

# 运行可执行文件
printf "${GREEN}============= running %s... ================================================${RESET}\n" "$target"
./"$target"  # 可执行文件在 bin 目录下，直接运行


