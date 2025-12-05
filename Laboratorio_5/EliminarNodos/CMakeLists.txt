cmake_minimum_required(VERSION 4.0)
project(EliminarNodos)

set(CMAKE_CXX_STANDARD 20)

add_executable(EliminarNodos main.cpp
            BibliotecaArbolBinarioBusqueda/funcionesArbolBinarioBusqueda.cpp
            BibliotecaCola/funcionesCola.cpp
            BibliotecaPila/funcionesPila.cpp)
