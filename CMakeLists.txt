cmake_minimum_required(VERSION 3.20)
project(Programowanie_Obiektowe_1 CXX)

set(CMAKE_CXX_STANDARD 17)

add_compile_options(
      "-pedantic"
      "-Wall"
      "-Weverything"
      "-Wno-c++98-compat"
      "-Wno-c++98-compat-pedantic"
      "-ferror-limit=16"
)

add_executable(Programowanie_Obiektowe_1
    workspace/main.cpp
    workspace/complex.cpp
)