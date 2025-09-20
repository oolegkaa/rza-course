cmake_minimum_required(VERSION 3.10)
project(week5)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add library for GPIO simulator class
add_library(gpio_simulator_lib STATIC gpio_simulator.cpp)

# Add executable
add_executable(gpio_simulator_test main.cpp)
target_link_libraries(gpio_simulator_test gpio_simulator_lib)

# Set compiler flags
target_compile_options(gpio_simulator_test PRIVATE
    -Wall
    -Wextra
    -Wpedantic
    -Werror
)

target_compile_options(gpio_simulator_lib PRIVATE
    -Wall
    -Wextra
    -Wpedantic
    -Werror
)