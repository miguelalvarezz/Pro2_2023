cmake_minimum_required(VERSION 3.24)
project(StaticStack C)

set(CMAKE_C_STANDARD 99)

add_executable(StaticStack main.c StaticStack.c StaticStack.h)
