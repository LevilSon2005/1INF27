//
// Created by binny on 26/09/2025.
//

#include "funcionesPila.hpp"

#include <iostream>
using namespace std;
#include "Pila.hpp"
/*
 * construir
 * esPilaVacia
 * apilar
 * desapilar
 * imprimir
 */

void construir(struct Pila& pilaTAD) {
    pilaTAD.inicio = nullptr;
}

bool esPilaVacia(struct Pila pilaTAD) {
    return (pilaTAD.inicio == nullptr);
}

void apilar(struct Pila& pilaTAD, struct ElementoPila elemento) {
    //CREAMOS EL NODO;
    struct NodoPila* nuevo_nodo;
    nuevo_nodo = new struct NodoPila;
    nuevo_nodo->elemento = elemento;
    nuevo_nodo->siguiente = nullptr;

    //INSERTAMOS EL NODO
    if (pilaTAD.inicio == nullptr) {
        pilaTAD.inicio = nuevo_nodo;
    }else {
        nuevo_nodo->siguiente = pilaTAD.inicio;
        pilaTAD.inicio = nuevo_nodo;
    }

}

void imprimir(struct Pila pilaTAD) {
    struct NodoPila* recorrido = pilaTAD.inicio;
    while (recorrido) {
        cout << recorrido->elemento.numero << " - ";
        recorrido = recorrido->siguiente;
    }
}