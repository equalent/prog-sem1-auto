cmake_minimum_required(VERSION 3.10)
project(progauto)

set(SOURCES
    src/main.c

    src/t98.c
    src/t99.c
)

add_executable(progauto ${SOURCES})