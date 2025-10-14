cmake_minimum_required(VERSION 4.0)
project(PasaPila)

set(CMAKE_CXX_STANDARD 20)

add_executable(PasaPila main.cpp
        BibliotecaPila/funcionesPila.cpp)
