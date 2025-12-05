#include "BibliotecaArbolBinarioBusqueda/funcionesArbolBinarioBusqueda.h"
#include "BibliotecaArbolBinarioBusqueda/ArbolBinarioBusqueda.h"
#include "BibliotecaCola/funcionesCola.h"
#include "BibliotecaCola/Cola.h"
#include <iostream>

#include "BibliotecaPila/funcionesPila.h"
using namespace std;

void imprimirNivelEnter(struct NodoArbolBinarioBusqueda* nodo) {
    struct Cola cola;
    construir(cola);
    struct ElementoCola c_elemento{nodo};
    encolar(cola, c_elemento);

    while (not esColaVacia(cola)) {
        int n_nodos_x_nivel = longitud(cola);
        for (int i=0;i<n_nodos_x_nivel;i++) {
            c_elemento = desencolar(cola);
            cout<<c_elemento.nodo->elemento.numero<<" ";

            if (!esNodoVacio(c_elemento.nodo->izquierda)) {
                struct ElementoCola c_izq{c_elemento.nodo->izquierda};
                encolar(cola, c_izq);
            }

            if (!esNodoVacio(c_elemento.nodo->derecha)) {
                struct ElementoCola c_der{c_elemento.nodo->derecha};
                encolar(cola, c_der);
            }
        }
        cout<<endl;
    }
}

struct NodoArbolBinarioBusqueda* busqueda_recursiva(struct NodoArbolBinarioBusqueda* nodo,
                                                    struct ElementoArbolBinarioBusqueda elemento) {
    if (nodo == nullptr) return nullptr;
    if (elemento.numero < nodo->elemento.numero) {
        return busqueda_recursiva(nodo->izquierda, elemento);
    }
    else {
        if(elemento.numero > nodo->elemento.numero) {
            return busqueda_recursiva(nodo->derecha, elemento);
        }
        else {//cuando son =
            return nodo;
        }
    }
}

struct NodoArbolBinarioBusqueda* eliminar_recursivo(struct NodoArbolBinarioBusqueda* nodo,struct ElementoArbolBinarioBusqueda elemento) {
    if (nodo == nullptr) return nullptr;
    if (elemento.numero < nodo->elemento.numero) {
        nodo->izquierda = eliminar_recursivo(nodo->izquierda, elemento);
    }else {
        if (elemento.numero > nodo->elemento.numero) {
            nodo->derecha = eliminar_recursivo(nodo->derecha, elemento);
        }
        else {
            if (esNodoVacio(nodo->izquierda) and esNodoVacio(nodo->derecha)) {
                delete nodo;
            }
            else if (esNodoVacio(nodo->izquierda)) {
                struct NodoArbolBinarioBusqueda* hijo = nodo->izquierda;
                delete nodo;
                return hijo;
            }
            else if (esNodoVacio(nodo->derecha)) {
                struct NodoArbolBinarioBusqueda* hijo = nodo->derecha;
                delete nodo;
                return hijo;
            }else {
                struct NodoArbolBinarioBusqueda * minNodo = minimoArbol(nodo->derecha);
                nodo->elemento = minNodo->elemento;
                nodo->derecha = eliminarRecursivo(nodo->derecha, minNodo->elemento);
            }
        }
    }
}

void eliminar_nodo(struct ArbolBinarioBusqueda& arbol, struct ElementoArbolBinarioBusqueda elemento) {
    eliminar_recursivo(arbol.raiz, elemento);
}

int main() {
    struct ArbolBinarioBusqueda arbol;
    construir(arbol);
    insertar(arbol, {50});
    insertar(arbol, {30});
    insertar(arbol, {70});
    insertar(arbol, {20});
    insertar(arbol, {40});
    insertar(arbol, {80});
    insertar(arbol, {60});
    insertar(arbol, {10});
    insertar(arbol, {55});
    insertar(arbol, {65});
    insertar(arbol, {90});

    cout<<"VERSION INICIAL: "<<endl;
    imprimirNivelEnter(arbol.raiz);
    cout<<"-------------------------------"<<endl;
/*
                50
              /    \
            30      70
           /  \    /  \
          20  40  60  80
         /       /  \   \
        10      55  65  90
*/
    //eliminar hoja
    cout<<"Eliminando 65: "<<endl;
    eliminar_nodo(arbol, {65});
    imprimirNivelEnter(arbol.raiz);
    cout<<"-------------------------------"<<endl;

    cout<<"Eliminando 20: "<<endl;
    eliminar_nodo(arbol, {20});
    imprimirNivelEnter(arbol.raiz);
    cout<<"-------------------------------"<<endl;

    cout<<"Eliminando 80: "<<endl;
    eliminar_nodo(arbol, {80});
    imprimirNivelEnter(arbol.raiz);
    cout<<"-------------------------------"<<endl;

    cout<<"Eliminando 50: "<<endl;
    eliminar_nodo(arbol, {50});
    imprimirNivelEnter(arbol.raiz);
    cout<<"-------------------------------"<<endl;
    return 0;
}