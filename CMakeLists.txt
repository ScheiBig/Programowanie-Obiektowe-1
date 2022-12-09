cmake_minimum_required(VERSION 3.20)
project(Programowanie_Obiektowe_1 CXX)

set(CMAKE_CXX_STANDARD 17)

add_compile_options(
    "-pedantic"
    "-Wall"
    "-Wno-old-style-cast"
    "-Wno-class-memaccess"
    "-fmax-errors=16"
    "-ggdb"
    "-fdiagnostics-color=always"
)

add_executable(Programowanie_Obiektowe_1
    # workspace/main.cpp
    # workspace/list.cpp
    # workspace/people.cpp
    zadanie_1.3/main.cpp
    zadanie_1.3/people.cpp
)