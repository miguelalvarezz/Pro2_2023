cmake_minimum_required(VERSION 3.24)
project(Queues C)

set(CMAKE_C_STANDARD 99)

add_executable(Queues main.c CircularStaticQueue.c CircularStaticQueue.h)
