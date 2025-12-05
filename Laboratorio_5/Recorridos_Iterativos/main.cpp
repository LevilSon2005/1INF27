#include "BibliotecaArbolBinarioBusqueda/funcionesArbolBinarioBusqueda.h"
#include "BibliotecaArbolBinarioBusqueda/ArbolBinarioBusqueda.h"
#include "BibliotecaPila/funcionesPila.h"
#include "BibliotecaPila/Pila.h"
#include <iostream>
using namespace std;

void recorrido_in_orden(const struct ArbolBinarioBusqueda &arbol) {
    struct Pila pila;
    construir(pila);

    struct NodoArbolBinarioBusqueda* nodo = arbol.raiz;

    while (nodo!=nullptr or !esPilaVacia(pila)) {

        while (nodo!=nullptr) {
            struct ElementoPila p_elemento {nodo};
            apilar(pila, p_elemento);
            nodo = nodo->izquierda ;
        }

        struct ElementoPila p2_elemento  = desapilar(pila);
        cout<<p2_elemento.nodo->elemento.numero<<"  ";
        nodo = p2_elemento.nodo;
        nodo = nodo->derecha;
    }

}

void recorrido_pre__orden(const struct ArbolBinarioBusqueda &arbol) {
    struct Pila pila;
    construir(pila);
    struct ElementoPila elemen{arbol.raiz};
    apilar(pila, elemen);

    while (!esPilaVacia(pila)) {
        elemen = desapilar(pila);
        cout<<elemen.nodo->elemento.numero<<"  ";

        if (!esNodoVacio(elemen.nodo->derecha)) {
            struct ElementoPila pder_elemento  = desapilar(pila);
            apilar(pila, pder_elemento);
        }
        if (!esNodoVacio(elemen.nodo->izquierda)) {
            struct ElementoPila pizq_elemento  = desapilar(pila);
            apilar(pila, pizq_elemento);
        }
    }
}

int main() {
    struct ArbolBinarioBusqueda arbol;
    construir(arbol);

    insertar(arbol, {50});
    insertar(arbol, {40});
    insertar(arbol, {20});
    insertar(arbol, {45});
    insertar(arbol, {55});
    insertar(arbol, {75});
    insertar(arbol, {60});

    recorrerEnOrden(arbol);
    cout<<endl;
    recorrido_in_orden(arbol);
    recorrido_pre__orden(arbol);
    return 0;
}