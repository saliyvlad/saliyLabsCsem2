cmake_minimum_required(VERSION 3.10)
project(TestSorting C)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -g")

# Поиск библиотеки CMocka
find_package(CMocka REQUIRED)
if (NOT CMocka_FOUND)
    message(FATAL_ERROR "CMocka library not found!")
endif()

# Список исходных файлов
set(SOURCES
    sorting.c
    unit_tests.c
)

# Создание исполняемого файла
add_executable(test_sorting ${SOURCES})
target_link_libraries(test_sorting PRIVATE cmocka)

# Настройка тестирования
enable_testing()
set(ENV{CMOCKA_MESSAGE_OUTPUT} "TAP")
add_test(NAME TestSorting COMMAND test_sorting)
