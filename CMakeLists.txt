cmake_minimum_required(VERSION 3.15)
project(Generic_Queue_C C)

set(CMAKE_C_STANDARD 99)

add_executable(Generic_Queue_C main.c Gen_Queue.c Gen_Queue.h)