cmake_minimum_required(VERSION 3.10)
project(week1)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add executable
add_executable(hello_world main.cpp)

# Set compiler flags
target_compile_options(hello_world PRIVATE
    -Wall
    -Wextra
    -Wpedantic
    -Werror
)