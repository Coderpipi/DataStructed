cmake_minimum_required(VERSION 3.0)

# 设置项目名字
project(DATASTRUCTED)

# 编译类型 Debug | Release
set(CMAKE_BUILD_TYPE Debug)

# 使用的编译器 clang++ | gcc
set(CMAKE_CXX_COMPILER "clang++")

# 编译选项
add_definitions("-std=c++11")
add_definitions("-O3")

# 设置可执行文件输出位置
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

# 设置静态库文件搜索位置
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

# 设置链接动态库文件的位置
link_directories(${PROJECT_SOURCE_DIR}/lib)

# 设置头文件搜索位置
include_directories(${PROJECT_SOURCE_DIR}/include)

# 设置编译时需要编译的文件以及可执行文件的名字
add_executable(main src/main.cc src/sort.cc)
