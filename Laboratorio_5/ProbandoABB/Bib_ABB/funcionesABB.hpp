//
// Created by binny on 24/11/2025.
//

#ifndef PROBANDOABB_FUNCIONESABB_HPP
#define PROBANDOABB_FUNCIONESABB_HPP

#include "ABB.hpp"
#include "../BibliotecaCola/Cola.h"
#include "../BibliotecaCola/funcionesCola.h"
#include "../BibliotecaPila/funcionesPila.h"
#include "../BibliotecaPila/Pila.h"
#include "../Utils.hpp"

void construir(struct ABB& arbol);
bool esArbolVacio(struct ABB arbol);
bool esNodoVacio(struct NodoABB* nodo);
void insertar(struct ABB &arbol, struct ElementoABB elemento);
void insertarRecursivo(struct NodoABB*& nodo, struct ElementoABB elemento);
void imprimir_amplitud_ID_Iterativo(const struct ABB &arbol);
void imprimir_amplitud_ID_Iterativo_enter(const struct ABB& arbol);
void imprimir_amplitud_reves(const struct ABB& arbol);
void imprimir_pre_orden_iterativo(const struct ABB& arbol);

#endif //PROBANDOABB_FUNCIONESABB_HPP
