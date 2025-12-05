cmake_minimum_required(VERSION 4.0)
project(Recorridos_Arboles)

set(CMAKE_CXX_STANDARD 20)

add_executable(Recorridos_Arboles main.cpp
                BibliotecaArbolBinario/funcionesArbolBinario.cpp
                BibliotecaCola/funcionesCola.cpp)
