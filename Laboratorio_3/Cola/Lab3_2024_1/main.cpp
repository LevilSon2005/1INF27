#include <iostream>
#include "BibliotecaCola/funcionesCola.h"
#include "BibliotecaCola/Cola.h"
using namespace std;
#define MAX_PACIENTES 6

void constuirColaPrioridad(struct Cola &cola) {
    cola.inicio = nullptr;
    cola.fin = nullptr;
    cola.last1 = nullptr;
    cola.last2 = nullptr;
}

// int HallarPrioridad(struct ElementoCola paciente) {
//     int edad = 2025-paciente.anio;
//
//     if (edad >= 80) return 1;
//     else if ( edad <=10) return 2;
//     else return 3;
// }

struct NodoCola* nodo(struct ElementoCola elemento) {
    struct NodoCola* nuevo;
    nuevo = new struct NodoCola;
    nuevo->elemento = elemento;
    nuevo->siguiente =  nullptr;
    return nuevo;
}

//todo: se inserta el Nodo nuevo despues del Nodo actual
void insertarDespues(struct Cola &cola, struct NodoCola* actual, struct NodoCola* nuevo) {
    //todo: para insertar al inicio
    if (actual == nullptr) {
        nuevo->siguiente = cola.inicio;
        cola.inicio = nuevo;
        if (cola.fin == nullptr) cola.fin = nuevo;
    }
    //todo: insertar despues
    else {
        nuevo->siguiente = actual->siguiente;
        actual->siguiente = nuevo;
        if (cola.fin == actual) cola.fin =  nuevo;
    }
}

void encolarPrioridad(struct Cola &cola, struct ElementoCola elemento, int prioridad) {
    struct NodoCola* nuevo_nodo = nodo(elemento);
    if (prioridad == 1) {
        //todo: la cola1 NO esta vacia
        if (cola.last1 != nullptr) {
            insertarDespues(cola, cola.last1, nuevo_nodo);
            cola.last1 = nuevo_nodo;
        }
        //todo: la cola1 esta vacia
        else {
            insertarDespues(cola, nullptr, nuevo_nodo);
            cola.last1 = nuevo_nodo;
        }
        return;
    }

    if (prioridad == 2) {
        if (cola.last2 != nullptr) {
            insertarDespues(cola, cola.last2, nuevo_nodo);
            cola.last2 = nuevo_nodo;
        }
        else if (cola.last1 != nullptr) {
            insertarDespues(cola,cola.last1, nuevo_nodo);
            cola.last2 = nuevo_nodo;
        }
        else {
            insertarDespues(cola, nullptr, nuevo_nodo);
            cola.last2 = nuevo_nodo;
        }

        return;
    }

    if (prioridad == 3) {
        if (cola.fin != nullptr) {
            insertarDespues(cola, cola.fin, nuevo_nodo);
        }else {
            insertarDespues(cola, nullptr, nuevo_nodo);
        }
    }
}

int main() {
    struct Cola colaPrioridad;
    constuirColaPrioridad(colaPrioridad);
    struct ElementoCola pacientes[MAX_PACIENTES]={
        {30,05,1943,"BXQ778"},
        {20,04,2014,"HRP112"},
        {26,06,1975,"PRL625"},
        {22,10,1949,"MKP157"},
        {13,05,2020,"ARH749"},
        {14,02,1930,"HRQ931"}
    };

    for(int i=0;i<MAX_PACIENTES;i++){
        encolarPrioridad(colaPrioridad, pacientes[i], HallarPrioridad(pacientes[i]));
    }

    imprimir(colaPrioridad);

    return 0;
}