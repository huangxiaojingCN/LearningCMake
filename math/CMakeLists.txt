
# 查找所有源文件, 将其存放到 SRC_DIR 变量中.
aux_source_directory(. SRC_DIR)

# 将源文件生成链接库
add_library(MathFunctions ${SRC_DIR})