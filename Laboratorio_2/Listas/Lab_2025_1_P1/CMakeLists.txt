cmake_minimum_required(VERSION 4.0)
project(Lab_2025_1_P1)

set(CMAKE_CXX_STANDARD 20)

add_executable(Lab_2025_1_P1 main.cpp
        BibliotecaLista/funcionesLista.cpp
        BibliotecaLista/funcionesLista.h
        BibliotecaLista/Lista.h
        BibliotecaLista/NodoLista.h
        BibliotecaLista/ElementoLista.h)
