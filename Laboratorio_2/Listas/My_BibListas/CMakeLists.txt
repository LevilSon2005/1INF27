cmake_minimum_required(VERSION 4.0)
project(My_BibListas)

set(CMAKE_CXX_STANDARD 20)

add_executable(My_BibListas main.cpp
        my_bibliotecaLista/BibliotecaLista.cpp
        my_bibliotecaLista/BibliotecaLista.hpp)
