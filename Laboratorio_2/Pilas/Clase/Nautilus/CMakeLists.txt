cmake_minimum_required(VERSION 4.0)
project(Nautilus)

set(CMAKE_CXX_STANDARD 20)

add_executable(Nautilus main.cpp
        Biblioteca_Pilas/funcionesPilas.cpp
        Biblioteca_Pilas/funcionesPilas.hpp
        Biblioteca_Pilas/NodoPila.hpp
        Biblioteca_Pilas/Pila.hpp
        Biblioteca_Pilas/ElementoPila.hpp)
