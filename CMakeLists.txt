cmake_minimum_required(VERSION 3.10)
project(RZA_Course)

# Установка стандартов языков
set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 11)

# Добавление поддиректорий для каждой недели
add_subdirectory(week1)
add_subdirectory(week2)
add_subdirectory(week3)
add_subdirectory(week4)
add_subdirectory(week5)
# add_subdirectory(week6)
# add_subdirectory(week7)

# Настройка общих флагов компиляции
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")

# Установка директории для бинарных файлов
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)