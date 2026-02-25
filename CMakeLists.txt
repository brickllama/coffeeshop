cmake_minimum_required(VERSION 4.2)

set(CMAKE_CXX_COMPILER "/usr/lib/llvm/21/bin/clang++-21")
set(CMAKE_CXX_STANDARD 26)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_EXPERIMENTAL_CXX_IMPORT_STD "d0edc3af-4c50-42ea-a356-e2862fe7a444")
set(CMAKE_CXX_SCAN_FOR_MODULES ON)
set(CMAKE_CXX_MODULE_STD 1)

project(coffeeshop LANGUAGES CXX)

add_subdirectory(src)
add_subdirectory(tests)

add_compile_options(-O3 -Wall -Wextra -Wpedantic)
