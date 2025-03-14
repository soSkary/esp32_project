cmake_minimum_required(VERSION 3.24)

project(embedded_project LANGUAGES CXX)

add_compile_options(-Wall -Wextra -Wpedantic)
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(executable_name main)
add_executable(${executable_name} main.cpp)

add_subdirectory(src)

target_include_directories(${executable_name} PUBLIC ${CMAKE_SOURCE_DIR}/include)

target_link_libraries(${executable_name} PUBLIC mainDevice)
