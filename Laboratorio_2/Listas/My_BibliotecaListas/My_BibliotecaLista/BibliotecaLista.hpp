//
// Created by binny on 24/09/2025.
//

#ifndef MY_BIBLIOTECALISTAS_BIBLIOTECALISTA_HPP
#define MY_BIBLIOTECALISTAS_BIBLIOTECALISTA_HPP

#include "Lista.h"
#include "NodoLista.h"
#include "ElementoLista.h"


void construir(struct Lista& listaTAD);
bool esListaVacia(struct Lista listaTAD);
struct NodoLista* obtenerUltimoNodo(struct Lista listaTAD) ;
void insertarAlInicio(struct Lista &listaTAD, struct ElementoLista elemento) ;
void insertarAlFinal(struct Lista &listaTAD, struct ElementoLista elemento) ;



#endif //MY_BIBLIOTECALISTAS_BIBLIOTECALISTA_HPP