//
// Created by binny on 25/09/2025.
//

#ifndef LAB_2025_1_P1_NODOLISTA_H
#define LAB_2025_1_P1_NODOLISTA_H

#include "ElementoLista.h"
struct NodoLista {
    struct ElementoLista elemento;
    struct NodoLista * siguiente;
};

#endif //LAB_2025_1_P1_NODOLISTA_H