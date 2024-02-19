cmake_minimum_required(VERSION 3.24)
project(ASD2023_L6_Liste_simple)

set(CMAKE_CXX_STANDARD 14)

include_directories(src)

add_executable(ASD2023_L6_Liste_simple
        src/ListeSimple.h
        src/LSIterator.h
        src/main.cpp
        src/util.cpp
        src/util.h)
