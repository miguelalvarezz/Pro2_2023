cmake_minimum_required(VERSION 3.24)
project(DynamicStack C)
set(CMAKE_C_STANDARD 99)

add_executable(DynamicStack main.c DynamicStack.c DynamicStack.h)