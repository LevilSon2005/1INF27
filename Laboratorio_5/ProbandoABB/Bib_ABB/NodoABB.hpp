//
// Created by binny on 24/11/2025.
//

#ifndef PROBANDOABB_NODOABB_HPP
#define PROBANDOABB_NODOABB_HPP

#include "ElementoABB.hpp"

struct NodoABB {
    struct ElementoABB elemento;
    struct NodoABB* derecha;
    struct NodoABB* izquierda;
};

#endif //PROBANDOABB_NODOABB_HPP