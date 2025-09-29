cmake_minimum_required(VERSION 4.0)
project(my_bibliotecaPilas)

set(CMAKE_CXX_STANDARD 20)

add_executable(my_bibliotecaPilas main.cpp
        My_BibiotecaPilas/NodoPila.hpp
        My_BibiotecaPilas/Pila.hpp
        My_BibiotecaPilas/funcionesPila.cpp
        My_BibiotecaPilas/funcionesPila.hpp
        My_BibiotecaPilas/ElementoPila.hpp
)
