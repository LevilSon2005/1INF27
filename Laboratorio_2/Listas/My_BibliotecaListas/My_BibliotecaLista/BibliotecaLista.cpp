//
// Created by binny on 24/09/2025.
//

#include "BibliotecaLista.hpp"

#include "Lista.h"

/*  construir  //inicilizar
 *  esListaVacia
 *  insertarAlInicio
 *  insertarAlFinal
 *  ObtenerUltimoNodo
 *  insertarEnOrden
 *  EliminaNodo
 *  Destruir   //destruir lista completa
 *  Imprimir
 */


void construir(struct Lista& listaTAD) {
    //inicializamos la lista - solo el inicio de la lista
    listaTAD.inicio = nullptr;
}

bool esListaVacia(struct Lista listaTAD) {
    return (listaTAD.inicio == nullptr);
}

//con & porque vamos a insertar un nuevo nodo
void insertarAlInicio(struct Lista &listaTAD, struct ElementoLista elemento) {
    //CREAMOS UN NUEVO NODO DONDE INSERTAR EL ELEMENTO
    struct NodoLista* nuevo_nodo;
    nuevo_nodo =  new struct NodoLista;
    nuevo_nodo->elemento = elemento;
    nuevo_nodo->siguiente = nullptr;

    //INSERTAMOS EN LA LISTA

    if (listaTAD.inicio == nullptr) { //si es la primera vez, aun está vacio
        listaTAD.inicio = nuevo_nodo;
    }
    else {
        nuevo_nodo->siguiente = listaTAD.inicio;
        listaTAD.inicio = nuevo_nodo;
    }
}

struct NodoLista* obtenerUltimoNodo(struct Lista listaTAD) {
    struct NodoLista* recorrido = listaTAD.inicio;
    while (recorrido->siguiente) {
        recorrido = recorrido->siguiente;
    }

    return recorrido;
}

void insertarAlFinal(struct Lista &listaTAD, struct ElementoLista elemento) {
    //CREAMOS EL NUEVO NODO
    struct NodoLista* nuevo_nodo;
    nuevo_nodo = new struct NodoLista;
    nuevo_nodo->elemento = elemento;
    nuevo_nodo->siguiente = nullptr;

    //INSERTAMOS
    if (listaTAD.inicio == nullptr) {
        listaTAD.inicio = nuevo_nodo;
    }else {
        struct NodoLista* ultimo = obtenerUltimoNodo(listaTAD);
        ultimo->siguiente = nuevo_nodo;
    }
}

