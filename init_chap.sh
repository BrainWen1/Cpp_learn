#!/bin/bash

chapter=$1
content=$2
name="chapter_${chapter}"

# 判断用户是否输入了章节序号
if [ -z "$chapter" ]; then
	echo "ERROR: Please enter the number of chapter."
	exit 1
fi

# 创建文件夹以及文件
mkdir -p "${name}"/{include,src}/"${name}" "${name}/test/txt" "${name}/bin"
touch "${name}"/{include,src}/"${name}"/.gitkeep "${name}/test/txt/.gitkeep" "${name}/test/${chapter}_1.cpp"

# 向源文件写入初始化内容
if [ -n "$content" ]; then
	echo "// ${content}" > "${name}/test/${chapter}_1.cpp"
fi

# 拷贝并修改CMakeLists.txt
cp "chapter_$(( chapter - 1 ))/CMakeLists.txt" "${name}/CMakeLists.txt"

read -p "INFO: if u wanna edit CMakeLists.txt? (Y/N): " choice

if [[ "$choice" =~ ^[Yy]$ ]]; then
    vim "${name}/CMakeLists.txt"
    echo "edit successfully."
else
    echo "jump successfully."
fi
