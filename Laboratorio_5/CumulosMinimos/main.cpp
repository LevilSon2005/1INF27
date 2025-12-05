#include "BibliotecaArbolBinarioBusqueda/ArbolBinarioBusqueda.h"
#include "BibliotecaArbolBinarioBusqueda/funcionesArbolBinarioBusqueda.h"
#include "BibliotecaCola/funcionesCola.h"
#include "BibliotecaCola/Cola.h"
#include <iostream>
using namespace std;

void imprimirNivelEnter(struct NodoArbolBinarioBusqueda* nodo) {
    if (esNodoVacio(nodo)) return;
    struct Cola cola;
    construir(cola);
    struct ElementoCola c_elemento{nodo};
    encolar(cola, c_elemento);

    while (not esColaVacia(cola)) {
        int cant_nodos = longitud(cola);
        for (int i=0;i<cant_nodos;i++) {
            c_elemento  = desencolar(cola);
            cout<<c_elemento.nodo->elemento.numero<<" ";
            if (!esNodoVacio(c_elemento.nodo->izquierda)) {
                struct ElementoCola c_izq {c_elemento.nodo->izquierda};
                encolar(cola,c_izq);
            }
            if (!esNodoVacio(c_elemento.nodo->derecha)) {
                struct ElementoCola c_der {c_elemento.nodo->derecha};
                encolar(cola,c_der);
            }
        }
        cout<<endl;
    }
}

void ordenarMinHeap(struct ArbolBinarioBusqueda& arbol) {

}

//insertar por nivel, de izquierda a derecha
void insertarMinHeap(struct ArbolBinarioBusqueda& arbol, struct ElementoArbolBinarioBusqueda elemento) {
    struct NodoArbolBinarioBusqueda* encontrado = nullptr;
    struct Cola cola;
    construir(cola);
    struct ElementoCola c_elemento;
    c_elemento.nodo = arbol.raiz;
    encolar(cola, c_elemento);

    if (esArbolVacio(arbol)) {
        plantarNodoArbolBinario(arbol.raiz, nullptr, elemento,nullptr);
    }
    //cuando al menos ya tiene la raiz
    else {
        //todo: encontramos el primer nodo que tenga al menos uno de sus hijos vacios
        while (not esColaVacia(cola)) {
            c_elemento = desencolar(cola);

            //todo: si alguno de sus hijos es vacio
            if (esNodoVacio(c_elemento.nodo->izquierda) or esNodoVacio(c_elemento.nodo->derecha)) {
                encontrado = c_elemento.nodo;
                break;
            }

            //TODO: Si no están vacíos, encolarlos para la siguiente iteración
            if (!esNodoVacio(c_elemento.nodo->izquierda)) {
                struct ElementoCola c_izq;  // ✅ Nueva variable
                c_izq.nodo = c_elemento.nodo->izquierda;
                encolar(cola, c_izq);
            }
            if (!esNodoVacio(c_elemento.nodo->derecha)) {
                struct ElementoCola c_der;  // ✅ Nueva variable
                c_der.nodo = c_elemento.nodo->derecha;
                encolar(cola, c_der);
            }
        }

        if (encontrado) {
            struct NodoArbolBinarioBusqueda* nuevoNodo = new NodoArbolBinarioBusqueda;
            nuevoNodo->elemento = elemento;
            nuevoNodo->izquierda = nullptr;
            nuevoNodo->derecha = nullptr;
            // nuevoNodo->padre = encontrado;  ← NO NECESARIO para conectar

            // Conectar desde el padre
            if (esNodoVacio(encontrado->izquierda)) {
                encontrado->izquierda = nuevoNodo;  // ← Conexión completa
            } else {
                encontrado->derecha = nuevoNodo;    // ← Conexión completa
            }
        }

        ordenarMinHeap(arbol);
    }
}


int main() {
    struct ArbolBinarioBusqueda arbol;
    construir(arbol);

    int arreglo[] = {3, 5, 7, 9, 8, 6, 2};
    int n = sizeof(arreglo) / sizeof(arreglo[0]);

    for (int i=0;i<n;i++) {
        insertarMinHeap(arbol,{arreglo[i]});
    }
    insertarMinHeap(arbol,{1});
    imprimirNivelEnter(arbol.raiz);
    return 0;
}
