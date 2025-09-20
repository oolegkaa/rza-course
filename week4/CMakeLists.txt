cmake_minimum_required(VERSION 3.10)
project(week4)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add library for signal logger class
add_library(signal_logger_lib STATIC signal_logger.cpp)

# Add executable
add_executable(signal_logger_test main.cpp)
target_link_libraries(signal_logger_test signal_logger_lib)

# Set compiler flags
target_compile_options(signal_logger_test PRIVATE
    -Wall
    -Wextra
    -Wpedantic
    -Werror
)

target_compile_options(signal_logger_lib PRIVATE
    -Wall
    -Wextra
    -Wpedantic
    -Werror
)