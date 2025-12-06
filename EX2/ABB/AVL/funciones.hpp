//
// Created by binny on 06/12/2025.
//

#ifndef AVL_FUNCIONES_HPP
#define AVL_FUNCIONES_HPP

#include "TAD.hpp"

int max(int &a, int &b);

int altura(Nodo *nodo);

int factor_balance(Nodo *nodo);
Nodo* rotacionDerecha(Nodo *y);
// Rotación simple a la IZQUIERDA (caso RR)
Nodo* rotacionIzquierda(Nodo *x);

#endif //AVL_FUNCIONES_HPP