//
// Created by binny on 25/09/2025.
//

#ifndef MY_BIBLISTAS_BIBLIOTECALISTA_HPP
#define MY_BIBLISTAS_BIBLIOTECALISTA_HPP

#include "Lista.h"
#include "NodoLista.h"
#include "ElementoLista.h"

using namespace std;
#include <iomanip>
#include <fstream>
#include <cstring>
#include <iostream>

void construir(struct Lista& listaTAD);
bool esListaVacia(struct Lista listaTAD);
struct NodoLista* obtenerUltimoNodo(struct Lista listaTAD) ;
void insertarAlInicio(struct Lista &listaTAD, struct ElementoLista elemento) ;
void insertarAlFinal(struct Lista &listaTAD, struct ElementoLista elemento) ;
void imprimir(struct Lista listaTAD);
void insertarEnOrden(struct Lista& listaTAD , struct ElementoLista elemento);
void eliminarNodo(struct Lista& listaTAD, struct ElementoLista elemento);
void destruir(struct Lista& listaTAD);

#endif //MY_BIBLISTAS_BIBLIOTECALISTA_HPP