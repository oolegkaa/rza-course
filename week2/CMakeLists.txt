cmake_minimum_required(VERSION 3.10)
project(week2)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)

# Add executable
add_executable(signal_analysis main.c)

# Set compiler flags
target_compile_options(signal_analysis PRIVATE
    -Wall
    -Wextra
    -Wpedantic
    -Werror
)