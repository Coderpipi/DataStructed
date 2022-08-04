cmake_minimum_required(VERSION 3.0)

# 设置项目名字
project(DATA-STRUCT)

# 编译类型 Debug | Release
set(CMAKE_BUILD_TYPE Debug)

# 使用的编译器 clang++ | gcc
set(CMAKE_CXX_COMPILER "clang++")

# 设置C++标准
set(CMAKE_CXX_STANDARD 14)

# 编译选项
add_definitions("-O2")

# 设置可执行文件输出位置
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

# 设置静态库文件搜索位置
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

# 设置链接动态库文件的位置
link_directories(${PROJECT_SOURCE_DIR}/lib)

# 设置头文件搜索位置
include_directories(${PROJECT_SOURCE_DIR}/include)

set(target main)
aux_source_directory(src all)
# 设置编译时需要编译的文件以及可执行文件的名字
add_executable(${target} src/main.cc ${all})