cmake_minimum_required(VERSION 3.26)
project(Point)

set(CMAKE_CXX_STANDARD 17)

add_executable(Point main.cpp
        Point3D.h
        Point3D.cpp)
