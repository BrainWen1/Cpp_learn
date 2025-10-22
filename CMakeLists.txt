# 1. 最低CMake版本（必须第一行）
cmake_minimum_required(VERSION 3.10.0)

# 设置「策略版本范围」（可选，让高版本 CMake 遵循指定范围的行为规则）
if(POLICY CMP0000)  # CMP0000 是 CMake 策略系统的“基础策略”，确保该机制能生效
    cmake_policy(VERSION 3.10...3.25)
endif()

# 2. 项目声明（名称、版本、语言）
project(cmake_study VERSION 1.0 LANGUAGES CXX)

# 3. 全局C++标准（所有子目标默认遵循）
set(CMAKE_CXX_STANDARD 17)          # 统一使用C++17
set(CMAKE_CXX_STANDARD_REQUIRED ON) # 强制要求标准，不兼容时报错
set(CMAKE_CXX_EXTENSIONS OFF)       # 禁用编译器扩展，保证可移植性

# 4. 全局构建类型配置（Debug/Release）
if(NOT CMAKE_BUILD_TYPE)
    # 默认构建类型为Debug（方便开发调试）
    set(CMAKE_BUILD_TYPE Debug CACHE STRING 
        "选择构建类型: Debug, Release, RelWithDebInfo, MinSizeRel" 
        FORCE
    )
endif()

# 5. 全局输出目录（所有目标的可执行文件/库文件集中存放）
# set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/chapter/bin)  # 可执行文件
# set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)  # 动态库
# set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)  # 静态库

# 6. 集成子目录（扫描并构建子目录中的目标）
# 每个子目录有自己的CMakeLists.txt
# add_subdirectory(chapter_2)
# add_subdirectory(chapter_3)
# add_subdirectory(chapter_4)
# add_subdirectory(chapter_5)
# add_subdirectory(chapter_6)
# add_subdirectory(chapter_7)
# add_subdirectory(chapter_8)
# add_subdirectory(chapter_9)
add_subdirectory(chapter_10)

# 7. 代码格式化工具（ClangFormat）- 全局工具配置
find_program(CLANG_FORMAT_EXECUTABLE clang-format)
if(CLANG_FORMAT_EXECUTABLE)
    # 递归查找所有C++源文件（包括子目录）
    file(GLOB_RECURSE ALL_CPP_FILES 
        ${CMAKE_SOURCE_DIR}/*.cpp 
        ${CMAKE_SOURCE_DIR}/*.h 
        ${CMAKE_SOURCE_DIR}/*.hpp
    )
    # 添加自定义目标：执行格式化（需手动调用 cmake --build . --target format）
    add_custom_target(format
        COMMAND ${CLANG_FORMAT_EXECUTABLE} -i -style=file ${ALL_CPP_FILES}
        COMMENT "使用clang-format格式化所有代码"
        VERBATIM
    )
endif()

# 8. 集成测试框架（CTest）- 全局测试配置
# enable_testing()  # 启用测试功能，子目录可添加具体测试用例
