cmake_minimum_required(VERSION 3.27)
project(2dgeom)

set(CMAKE_CXX_STANDARD 17)

add_executable(2dgeom main.cpp
        Line.cpp
        Line.h
        Point.cpp
        Point.h)
