cmake_minimum_required(VERSION 4.0)
project(Lab5_2023_2_SKYNERD)

set(CMAKE_CXX_STANDARD 20)

add_executable(Lab5_2023_2_SKYNERD main.cpp
                BibliotecaArbolBinarioBusqueda/funcionesArbolBinarioBusqueda.cpp
                BibliotecaPila/funcionesPila.cpp
                BibliotecaCola/funcionesCola.cpp
        funcionesSkynerd.cpp
        funcionesSkynerd.hpp)
