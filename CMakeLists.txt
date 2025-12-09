cmake_minimum_required(VERSION 3.16)
project(embedded_template C)

set(CMAKE_C_STANDARD 99)

add_compile_options(-Wall -Wextra -Werror)

add_subdirectory(hal)
add_subdirectory(domain)
add_subdirectory(app)
add_subdirectory(tests)
