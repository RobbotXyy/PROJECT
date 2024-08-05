#!/bin/bash

# 定义编译器和编译选项
COMPILER="g++"
CFLAGS="-std=c++11"  # 选择适合你项目的C++标准
OUTPUT="work5"

# 源文件列表
SOURCES="Factory.cpp main.cpp"

# 编译项目
echo "Compiling project..."
$COMPILER $CFLAGS $SOURCES -o $OUTPUT

# 检查编译是否成功
if [ $? -eq 0 ]; then
    echo "Compilation successful."
    echo "Running $OUTPUT..."
    ./$OUTPUT
else
    echo "Compilation failed."
fi