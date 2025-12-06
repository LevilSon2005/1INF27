//
// Created by binny on 06/12/2025.
//

#ifndef AVL_TAD_HPP
#define AVL_TAD_HPP

struct Nodo{
    int dni;
    int altura;
    struct Nodo* izq;
    struct Nodo* der;
};

struct ABB{
    struct Nodo* raiz;
};

#endif //AVL_TAD_HPP