cmake_minimum_required(VERSION 3.10)
project(CustomVector)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(CustomVector
    main.cpp
    vector.cpp
    vector.h
    static_array.h
    sort.h
)
