//
// Created by binny on 25/09/2025.
//
#include "BibliotecaLista.hpp"

#include <iostream>

/*
 * construir
 * esListVacia
 * insertarAlInicio
 * obtenerUltimoNodo
 * insertarAlFinal
 * insertarEnOrden
 * eliminarNodo
 * destruir  - destruir lista
 * imprimir
 */

void construir(struct Lista& listaTAD) {
    listaTAD.inicio =  nullptr;
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


void imprimir(struct Lista listaTAD) {
    struct NodoLista* recorrido  = listaTAD.inicio;
    if (esListaVacia(listaTAD)) cout<<"La lista está vacía"<<endl;
    else {
        cout<<"[ ";
        bool inicioLista = true;
        while (recorrido) {
            if ( not inicioLista) cout<<" , ";
            cout<<recorrido->elemento.codigo;
            inicioLista = false;
            recorrido = recorrido->siguiente;
        }
        cout<<" ]"<<endl;
    }
}

//insertamos en orden ascendente de izq a derecha
void insertarEnOrden(struct Lista& listaTAD , struct ElementoLista elemento) {
    struct NodoLista* nuevo_nodo;
    nuevo_nodo = new struct NodoLista;
    nuevo_nodo->elemento = elemento;
    nuevo_nodo->siguiente = nullptr;

    if ( listaTAD.inicio == nullptr) listaTAD.inicio = nuevo_nodo;
    else {
        struct NodoLista* anterior = nullptr;
        struct NodoLista* recorrido = listaTAD.inicio;
        while (recorrido!=nullptr and recorrido->elemento.codigo < nuevo_nodo->elemento.codigo) {
            anterior = recorrido;
            recorrido = recorrido->siguiente;
        }
        nuevo_nodo->siguiente = recorrido;
        if (anterior!= nullptr)anterior->siguiente = nuevo_nodo;
        else {
            listaTAD.inicio = nuevo_nodo;
        }
    }
}


void eliminarNodo(struct Lista& listaTAD, struct ElementoLista elemento) {
    struct NodoLista* recorrido = listaTAD.inicio;
    struct NodoLista* anterior = nullptr;
    while (recorrido) {
        if (recorrido->elemento.codigo == elemento.codigo) {
            struct NodoLista* nodoEliminar = recorrido;
            if (anterior!= nullptr) anterior->siguiente = recorrido->siguiente;
            else listaTAD.inicio = recorrido->siguiente;
            delete nodoEliminar;
            break;
        }
        anterior = recorrido;
        recorrido = recorrido->siguiente;
    }
}

void destruir(struct Lista& listaTAD) {
    struct NodoLista* recorrido = listaTAD.inicio;
    while (recorrido) {
        struct NodoLista* nodoEliminar = recorrido;
        recorrido = recorrido->siguiente;
        delete nodoEliminar;
    }
    listaTAD.inicio = nullptr;
}