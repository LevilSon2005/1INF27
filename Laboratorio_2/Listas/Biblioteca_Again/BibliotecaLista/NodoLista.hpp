//
// Created by binny on 10/10/2025.
//

#ifndef BIBLIOTECA_AGAIN_NODOLISTA_HPP
#define BIBLIOTECA_AGAIN_NODOLISTA_HPP
#include "ElementoLista.hpp"
struct NodoLista {
    struct ElementoLista elemento;
    struct NodoLista* siguiente;
};

#endif //BIBLIOTECA_AGAIN_NODOLISTA_HPP