cmake_minimum_required(VERSION 3.10)
project(week3)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add library for digital signal class
add_library(digital_signal_lib STATIC digital_signal.cpp)

# Add executable
add_executable(digital_signal_test main.cpp)
target_link_libraries(digital_signal_test digital_signal_lib)

# Set compiler flags
target_compile_options(digital_signal_test PRIVATE
    -Wall
    -Wextra
    -Wpedantic
    -Werror
)

target_compile_options(digital_signal_lib PRIVATE
    -Wall
    -Wextra
    -Wpedantic
    -Werror
)