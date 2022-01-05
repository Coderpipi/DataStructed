cmake_minimum_required(VERSION 3.0)

project(DATASTRUCTED)

set(CMAKE_BUILD_TYPE Debug)

set(CMAKE_CXX_COMPILER "clang++")

add_definitions("-std=c++11")

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

link_directories(${PROJECT_SOURCE_DIR}/lib)

include_directories(${PROJECT_SOURCE_DIR}/include)

add_executable(main src/main.cc src/sort.cc)
