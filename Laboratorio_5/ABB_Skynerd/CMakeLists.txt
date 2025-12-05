cmake_minimum_required(VERSION 4.0)
project(ABB_Skynerd)

set(CMAKE_CXX_STANDARD 20)

add_executable(ABB_Skynerd main.cpp
                BibliotecaArbolBinarioBusqueda/funcionesArbolBinarioBusqueda.cpp
                BibliotecaCola/funcionesCola.cpp)
