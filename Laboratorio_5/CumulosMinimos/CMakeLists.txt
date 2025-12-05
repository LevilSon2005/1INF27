cmake_minimum_required(VERSION 4.0)
project(CumulosMinimos)

set(CMAKE_CXX_STANDARD 20)

add_executable(CumulosMinimos main.cpp
                BibliotecaPila/funcionesPila.cpp
                BibliotecaCola/funcionesCola.cpp
                BibliotecaArbolBinarioBusqueda/funcionesArbolBinarioBusqueda.cpp)
