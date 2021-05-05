cmake_minimum_required(VERSION 3.19)
project(DSA_Mini_Project C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(DSA_Mini_Project
        common.h
        header.h
        list.c
        list.h
        main.c
        person.c
        person.h
        station.c
        station.h
        vector.c
        vector.h)
