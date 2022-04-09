cmake_minimum_required(VERSION 2.8)  # CMake version check
project(linklist)               # Create project "simple_example"
add_definitions(-std=c++11)

# Add main.cpp file of project root directory as source file
set(SOURCE_FILES linklist.cpp)

# Add executable target with source files listed in SOURCE_FILES variable
add_executable(linklist ${SOURCE_FILES})
