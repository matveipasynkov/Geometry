cmake_minimum_required(VERSION 3.28)
project(FifthEDZ)

set(CMAKE_CXX_STANDARD 17)

add_executable(FifthEDZ main.cpp
        ishape.h
        point.h
        src/point.cpp
        vector.h
        src/ishape.cpp
        segment.h
        src/segment.cpp
        src/vector.cpp
        line.h
        src/line.cpp
        ray.h
        src/ray.cpp
        circle.h
        src/circle.cpp
        polygon.h
        src/polygon.cpp)
