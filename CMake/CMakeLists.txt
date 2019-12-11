cmake_minimum_required(VERSION 3.15)
project(crosswordsMiner C)

set(CMAKE_C_STANDARD 99)

add_executable(crosswordsMiner ../main.c ../crossWord.h)
