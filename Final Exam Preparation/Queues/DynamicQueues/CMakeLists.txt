cmake_minimum_required(VERSION 3.24)
project(DynamicQueues C)

set(CMAKE_C_STANDARD 99)

add_executable(DynamicQueues main.c DynamicQueue.c DynamicQueue.h)
