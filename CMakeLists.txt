# 支持 cmake 最小版本为 2.6
cmake_minimum_required(VERSION 2.6)

# 项目名称
project(Demo3)

# 引入头文件，对源码进行配置
configure_file(
    "${PROJECT_SOURCE_DIR}/config.h.in"
    "${PROJECT_BINARY_DIR}/config.h"
)

# 可选配置，可对变量 MY_MATH_FLAG 进行设置开关 ON/OFF
option(MY_MATH_FLAG 
    "是否使用自定义函数实现开平方计算"
    OFF
)

if (MY_MATH_FLAG)
    # 将源文件下 math 目录头文件添加到编译器头文件搜索目录.
    include_directories ("${PROJECT_SOURCE_DIR}/math")
    # 将 math 目录加入到 cmake 构建. 会执行子目录中的 CMakeLists.txt
    add_subdirectory(math)
    set(EXTRA_LIBS ${EXTRA_LIBS} MathFunctions)
endif(MY_MATH_FLAG)


# 指定源代码，生成可执行文件 Demo1
# 这里也可以使用 aux_source_directory(. SRC_DIR) 来替换，这样的好处就是不用写多个源文件
add_executable(Demo3 main.c)

# 将 MathFunctions 链接到 Demo1
target_link_libraries(Demo3 ${EXTRA_LIBS})