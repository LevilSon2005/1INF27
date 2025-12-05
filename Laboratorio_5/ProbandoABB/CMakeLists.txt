cmake_minimum_required(VERSION 4.0)
project(ProbandoABB)

set(CMAKE_CXX_STANDARD 20)

add_executable(ProbandoABB main.cpp
        Bib_ABB/funcionesABB.cpp
        Bib_ABB/funcionesABB.hpp
        Bib_ABB/ABB.hpp
        Bib_ABB/NodoABB.hpp
        Bib_ABB/ElementoABB.hpp
        Utils.hpp
        BibliotecaCola/funcionesCola.cpp
        BibliotecaCola/funcionesCola.h
        BibliotecaPila/funcionesPila.cpp
        BibliotecaPila/funcionesPila.h
)
