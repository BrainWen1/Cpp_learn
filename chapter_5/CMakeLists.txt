# 1. 可执行文件输出目录
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)

# 2. 添加可执行目标（当前目录的源文件）
set(SOURCE_FILE 5_3)
add_executable(${SOURCE_FILE} ${SOURCE_FILE}.cpp)

# 3. 目标专属编译选项（警告、优化等，仅对当前目录的目标生效）
# 针对GCC/Clang添加严格警告
if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    # 开启基本警告
    set(BASIC_WARNINGS 
        -Wall                # 基础警告
        -Wextra              # 额外警告
        -Wpedantic           # 严格遵循 C++ 标准
    )
    # 忽略部分警告
    set(DISABLED_WARNINGS
        -Wno-unused-variable # 未使用变量
        -Wno-dangling-else   # 悬垂else
        -Wno-empty-body      # 空语句体
        -Wno-unused-but-set-variable #初始化未使用变量
    )

    foreach(target ${SOURCE_FILE})
        target_compile_options(
            ${target} PRIVATE
            ${BASIC_WARNINGS}
            ${DISABLED_WARNINGS}
        )
    endforeach()    
endif()

# 4. 目标专属头文件目录
# target_include_directories(4_11 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/header)

# 5. 目标链接库（若需要依赖其他库，如自定义库或系统库）
# target_link_libraries(4_11 PRIVATE utils)

# 6. 为当前目录的目标添加测试用例（配合根目录的 enable_testing）
#add_test(
#    NAME Test_4_11  # 测试名称为Test_4_11，执行4_11可执行文件，执行目录（chapter_4/bin）
#    COMMAND 4_11 < in.txt
#    WORKING_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}
#)

#set_tests_properties(
#    Test_4_11 PROPERTIES
#    PASS_REGULAR_EXPRESSION "everything is fine." # 可选：检查输出是否符合预期
#)