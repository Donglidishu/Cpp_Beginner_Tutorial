# CMake 最低版本要求
cmake_minimum_required(VERSION 3.10)

# 项目名称
project(test105)

# 设置 C++ 标准
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# 包含头文件目录
include_directories(${PROJECT_SOURCE_DIR}/include)

# 自动查找源文件
file(GLOB SOURCES
    ${PROJECT_SOURCE_DIR}/src/*.cpp
)

# 生成可执行文件
add_executable(test105 ${SOURCES})