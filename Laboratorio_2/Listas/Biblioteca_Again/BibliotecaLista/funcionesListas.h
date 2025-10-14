//
// Created by binny on 10/10/2025.
//

#ifndef BIBLIOTECA_AGAIN_FUNCIONESLISTAS_H
#define BIBLIOTECA_AGAIN_FUNCIONESLISTAS_H

#include "Lista.h"
#include <iostream>

using namespace std;

void construir(struct Lista & listaTAD);
bool esListaVacia(const struct Lista & listaTAD);
void insertarAlInicio(struct Lista & listaTAD, const struct ElementoLista & elemento);
void insertarAlFinal(struct Lista & listaTAD, const struct ElementoLista & elemento);
struct NodoLista * obtenerUltimoNodo(const struct Lista & listaTAD);
void insertarEnOrden(struct Lista & listaTAD, const struct ElementoLista & elemento);
void eliminaNodo(struct Lista & listaTAD, const struct ElementoLista & elemento);
void destruir(struct Lista & listaTAD) ;
void imprimir(const struct Lista & listaTAD);

#endif //BIBLIOTECA_AGAIN_FUNCIONESLISTAS_H