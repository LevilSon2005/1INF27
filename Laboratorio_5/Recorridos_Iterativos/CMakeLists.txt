cmake_minimum_required(VERSION 4.0)
project(Recorridos_Iterativos)

set(CMAKE_CXX_STANDARD 20)

add_executable(Recorridos_Iterativos main.cpp
                BibliotecaPila/funcionesPila.cpp
                BibliotecaCola/funcionesCola.cpp
                BibliotecaArbolBinarioBusqueda/funcionesArbolBinarioBusqueda.cpp)
