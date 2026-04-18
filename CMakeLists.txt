cmake_minimum_required(VERSION 3.20)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(MyProject LANGUAGES CXX)

find_package(ZLIB REQUIRED)
find_package(GTest REQUIRED)

add_subdirectory(./src)
add_subdirectory(./ut)