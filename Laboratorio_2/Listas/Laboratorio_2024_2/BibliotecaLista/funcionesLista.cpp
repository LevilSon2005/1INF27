//
// Created by binny on 26/09/2025.
//

#include "funcionesLista.h"

//Fecha:  sÃ¡bado 30 Agosto 2025
//Autor: Ana Roncal

#include <iostream>
#include <iomanip>
#include "Lista.h"
#include "funcionesLista.h"
using namespace std;

void construir(struct Lista & listaTAD) {
    listaTAD.inicio = nullptr;
}

bool esListaVacia(const struct Lista & listaTAD) {
    return listaTAD.inicio == nullptr;
}

/*Inserta los elementos al inicio de la lista*/
void insertarAlInicio(struct Lista & listaTAD, const struct ElementoLista & elemento) {

    struct NodoLista * nuevo;
    nuevo = new struct NodoLista;
    nuevo->elemento = elemento;
    nuevo->siguiente = listaTAD.inicio;
    listaTAD.inicio = nuevo;
}

/*Inserta un elemento siempre al final de la lista*/
void insertarAlFinal(struct Lista & listaTAD, const struct ElementoLista & elemento) {

    struct NodoLista * ultimoNodoLista = obtenerUltimoNodo(listaTAD);
    struct NodoLista * nuevo;
    nuevo = new struct NodoLista;
    nuevo->elemento = elemento;
    nuevo->siguiente = nullptr;

    if (ultimoNodoLista == nullptr) /*Si la lista estÃ¡ vacÃ­a*/
        listaTAD.inicio = nuevo; /*se inserta en la cabeza de la lista*/
    else //La lista ya tiene NodoListas
        ultimoNodoLista->siguiente = nuevo;
}

/*Obtiene el Ãºltimo NodoLista de la lista*/
struct NodoLista * obtenerUltimoNodo(const struct Lista & listaTAD) {
    struct NodoLista * ultimo = nullptr;
    struct NodoLista* recorrido = listaTAD.inicio;

    while (recorrido != nullptr) {
        ultimo = recorrido;
        recorrido = recorrido->siguiente;
    }
    return ultimo;
}

void insertarEnOrden(struct Lista & listaTAD, const struct ElementoLista & elemento) {
    int tiempoTotal_elemento =  elemento.tiempoEstimadoViaje + elemento.tiempoPreparacion;
    struct NodoLista *nuevo, *recorrido = listaTAD.inicio, * anterior = nullptr;
    nuevo = new struct NodoLista;
    nuevo->elemento = elemento;
    while(recorrido){
        int tiempoTotal_recorrido = recorrido->elemento.tiempoEstimadoViaje +
                                    recorrido->elemento.tiempoPreparacion;
        if(tiempoTotal_recorrido < tiempoTotal_elemento) break;
        anterior = recorrido;
        recorrido = recorrido->siguiente;
    }
    nuevo->siguiente = recorrido;
    if(anterior == nullptr) listaTAD.inicio = nuevo;
    else anterior->siguiente = nuevo;
}

void eliminaNodo(struct Lista & listaTAD, const struct ElementoLista & elemento) {
    int tiempoTotal_elemento =  elemento.tiempoEstimadoViaje + elemento.tiempoPreparacion;
    struct NodoLista * ultimo = nullptr;
    struct NodoLista * recorrido = listaTAD.inicio;
    /*Avanzo hasta encontrar el elemento*/
    /*Si no lo encuentra no elimina nada*/
    while ((recorrido != nullptr) and (recorrido->elemento.tiempoEstimadoViaje +
        recorrido->elemento.tiempoPreparacion != tiempoTotal_elemento)) {
        ultimo = recorrido;
        recorrido = recorrido->siguiente;
    }

    if (recorrido != nullptr) {
        if (ultimo == nullptr) /*Estoy al inicio de la lista*/
            listaTAD.inicio = recorrido->siguiente;
        else
            ultimo->siguiente = recorrido->siguiente;
        delete recorrido; /*libera la memoria*/
    }
}

void destruir(struct Lista & listaTAD) {
    /*recorrido apunta al inicio del tad*/
    struct NodoLista * recorrido = listaTAD.inicio;

    while (recorrido != nullptr) {
        /*NodoLista auxiliar que va servir para eliminar los NodoListas*/
        struct NodoLista * NodoListaAEliminar = recorrido;
        recorrido = recorrido->siguiente;
        delete NodoListaAEliminar;
    }
    /*la lista queda vacia*/
    listaTAD.inicio = nullptr;

}

/*con const aquello que pasas no va cambiar, el compilador se da cuenta que es constante*/
void imprimir(const struct Lista & listaTAD) {

    if (esListaVacia(listaTAD)) {
        cout << "La lista esta vacia no se puede mostrar" << endl;
    } else {
        struct NodoLista * recorrido = listaTAD.inicio;
        int estaImprimiendoLaCabeza = 1;
        cout << "[";

        while (recorrido != nullptr) {
            int tiempoTotal_recorrido = recorrido->elemento.tiempoEstimadoViaje + recorrido->elemento.tiempoPreparacion;
            /*Este artificio coloca las comas despuÃƒÂ©s de la cabeza*/
            if ( not estaImprimiendoLaCabeza)
                cout << ", ";
            estaImprimiendoLaCabeza = 0;
            cout << recorrido->elemento.id<<" "<<tiempoTotal_recorrido;
            recorrido = recorrido->siguiente;
        }
        cout << "]" << endl;
    }
}