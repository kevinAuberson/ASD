cmake_minimum_required(VERSION 3.16)
project(ASD2023-L2-Recursivite)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wconversion -Wsign-conversion -pedantic")
add_executable(ASD2023-L2-Recursivite main.cpp pieces.cpp Carte.h Carte.cpp resolutionCartes.cpp resolutionCartes.h)