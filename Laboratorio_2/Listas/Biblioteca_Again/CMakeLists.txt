cmake_minimum_required(VERSION 4.0)
project(Biblioteca_Again)

set(CMAKE_CXX_STANDARD 20)

add_executable(Biblioteca_Again main.cpp
        BibliotecaLista/funcionesListas.cpp
        BibliotecaLista/funcionesListas.h
        BibliotecaLista/Lista.h
        BibliotecaLista/ElementoLista.hpp
        BibliotecaLista/NodoLista.hpp)
