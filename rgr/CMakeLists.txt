cmake_minimum_required(VERSION 3.10)
project(MatrixInverse C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

# Добавьте математическую библиотеку
find_package(Threads REQUIRED)
add_executable(matrix_inverse main.c matrix.c matrix.h)
target_link_libraries(matrix_inverse m)  # Подключаем математическую библиотеку

# Для Windows, используйте .dll, для Linux/Mac используйте .so
if(WIN32)
    add_library(matrix_lib SHARED matrix.c matrix.h)
else()
    add_library(matrix_lib SHARED matrix.c matrix.h)
endif()
