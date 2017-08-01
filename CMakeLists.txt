cmake_minimum_required(VERSION 3.3)
project(ArcherOpenMP)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp)

add_executable(ArcherOpenMP ${SOURCE_FILES})
