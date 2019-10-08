# 支持 cmake 最小版本为 2.6
cmake_minimum_required(VERSION 2.6)

# 项目名称
project(Demo2)

# 将源文件下 math 目录头文件添加到编译器头文件搜索目录.
include_directories ("${PROJECT_SOURCE_DIR}/math")

add_subdirectory(math)

# 指定源代码，生成可执行文件 Demo1
add_executable(Demo2 main.c)

# 将 MathFunctions 链接到 Demo1
target_link_libraries(Demo2 MathFunctions)