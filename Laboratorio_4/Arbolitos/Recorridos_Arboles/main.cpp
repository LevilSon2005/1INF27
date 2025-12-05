#include <iostream>
#include "BibliotecaArbolBinario/ArbolBinario.h"
#include "BibliotecaArbolBinario/funcionesArbolBinario.h"
#include "BibliotecaCola/funcionesCola.h"
#include "BibliotecaCola/Cola.h"
using namespace std;

//struct NodoArbolBinario *raiz
//ABB : IRD
void recorrido_InOrden_recursivo(struct NodoArbolBinario *&nodo) {
    if (not esNodoVacio(nodo)) {
        recorrido_InOrden_recursivo(nodo->izquierda);
        imprimirNodo(nodo);
        recorrido_InOrden_recursivo(nodo->derecha);
    }
}

void recorrido_InOrden(struct ArbolBinario &arbol) {
    recorrido_InOrden_recursivo(arbol.raiz);
}

//Reconstruccion: RID
void recorrido_PreOrden_recursivo(struct NodoArbolBinario* &nodo) {
    if ( not esNodoVacio(nodo) ) {
        imprimirNodo(nodo);
        recorrido_PreOrden_recursivo(nodo->izquierda);
        recorrido_PreOrden_recursivo(nodo->derecha);
    }
}

void recorrido_PreOrden(struct ArbolBinario &arbol) {
    recorrido_PreOrden_recursivo(arbol.raiz);
}

//Eliminiacion: IDR
void recorrido_PostOrden_recursivo(struct NodoArbolBinario*& nodo) {
    if (not esNodoVacio(nodo)) {
        recorrido_PostOrden_recursivo(nodo->izquierda);
        recorrido_PostOrden_recursivo(nodo->derecha);
        imprimirNodo(nodo);
    }
}

void recorrido_PostOrden(struct ArbolBinario &arbol) {
    recorrido_PostOrden_recursivo(arbol.raiz);
}

void recorrido_PorAmplitud_iterativo(const struct ArbolBinario &arbol){
    //primero sacamos la raiz
    if (arbol.raiz == nullptr) {
        cout<<"Arbol vacio"<<endl;
        return;
    };
    struct NodoArbolBinario* nodo = arbol.raiz;

    struct Cola cola;
    construir(cola);
    struct ElementoCola elemento_cola;
    elemento_cola.nodo = nodo;
    encolar(cola, elemento_cola);

    while (not esColaVacia(cola)) {
        struct ElementoCola elemento_actual = desencolar(cola);
        struct NodoArbolBinario* actual = elemento_actual.nodo;
        imprimirNodo(actual);

        if (not esNodoVacio(actual->izquierda)) {
            struct ElementoCola elemento_izq;
            elemento_izq.nodo = actual->izquierda;
            encolar(cola, elemento_izq);
        }

        if (not esNodoVacio(actual->derecha)) {
            struct ElementoCola elemento_der;
            elemento_der.nodo = actual->derecha;
            encolar(cola, elemento_der);
        }
    }
}

void amplitud_recursivo(struct Cola &cola) {
    if (esColaVacia(cola)) return;

    struct ElementoCola elemento_actual = desencolar(cola);
    struct NodoArbolBinario* actual = elemento_actual.nodo;
    imprimirNodo(actual);

    if (not esNodoVacio(actual->izquierda)) {
        struct ElementoCola elemento_izq;
        elemento_izq.nodo = actual->izquierda;
        encolar(cola, elemento_izq);
    }

    if (not esNodoVacio(actual->derecha)) {
        struct ElementoCola elemento_der;
        elemento_der.nodo = actual->derecha;
        encolar(cola, elemento_der);
    }
    amplitud_recursivo(cola);
}

void recorrido_PorAmplitud_recursivo(struct ArbolBinario &arbol) {
    if (arbol.raiz == nullptr) {
        cout<<"Arbol raiz"<<endl;
        return;
    }

    struct Cola cola;
    construir(cola);
    struct ElementoCola elemento_cola;
    elemento_cola.nodo = arbol.raiz;
    encolar(cola,elemento_cola );
    amplitud_recursivo(cola);
};

// void recorrido_InOrden_Iterativo(arbol);

int main() {
    struct ArbolBinario arbol;
    struct ArbolBinario arbolVacio, arbol1, arbol2, arbol3, arbol4; //tercer nivel
    struct ArbolBinario hijo_izquierdo, hijo_derecho; //segundo nivel

    /*                100
     *             /       \
     *           50        150
     *         /   \      /   \
     *       25    80    120   200
     *      /  \  /  \  /  \  /  \
     *  null nu  nu nu nul nu nu null
     */

    //todo: construil es para inicializarlo en nullptr, OBLIGATORIO para ArbolVacio
    construir(arbolVacio); //para que cada subarbol tenga raiz y las hijas izquierda y derecha con nullptr
    plantarArbolBinario(arbol1,arbolVacio, {25},arbolVacio);
    plantarArbolBinario(arbol2, arbolVacio, {80}, arbolVacio);
    plantarArbolBinario(arbol3, arbolVacio, {120}, arbolVacio);
    plantarArbolBinario(arbol4, arbolVacio, {200}, arbolVacio);

    plantarArbolBinario(hijo_izquierdo, arbol1, {50}, arbol2);
    plantarArbolBinario(hijo_derecho, arbol3, {150}, arbol4);

    plantarArbolBinario(arbol, hijo_izquierdo, {100}, hijo_derecho);
    cout<<"InOrden (IRD): ";
    recorrido_InOrden(arbol);
    cout<<endl;
    cout<<"PreOrden (RID): ";
    recorrido_PreOrden(arbol);
    cout<<endl;
    cout<<"PostOrden (IDR):";
    recorrido_PostOrden(arbol);
    cout<<endl;
    cout<<"Recorrido por amplitud (iterativo): ";
    recorrido_PorAmplitud_iterativo(arbol);
    cout<<endl;
    cout<<"Recorrido por amplitud (recursivo): ";
    recorrido_PorAmplitud_recursivo(arbol);
    cout<<endl;
    // recorrido_InOrden_Iterativo(arbol);
    return 0;
}