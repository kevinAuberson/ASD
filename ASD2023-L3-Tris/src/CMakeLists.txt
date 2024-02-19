 cmake_minimum_required(VERSION 3.16)
project(ASD-Labos-2021)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wconversion -Wsign-conversion -pedantic")

add_executable(Test-Tri mainTestTris.cpp testTris_impl.h mesuresTris.h mesuresTris.cpp triRapide_impl.h triParBase_impl.h)
add_executable(Temps-Tri mainMesureTris.cpp triRapide_impl.h triParBase_impl.h testTris_impl.h mesuresTris.h mesuresTris.cpp csv.h csv.cpp triParBase.h triRapide.h testTris.h mesureTris_impl.h)
