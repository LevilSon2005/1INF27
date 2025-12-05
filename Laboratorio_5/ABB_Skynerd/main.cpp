#include <iostream>
#include "BibliotecaCola/funcionesCola.h"
#include "BibliotecaCola/Cola.h"
#include "BibliotecaArbolBinarioBusqueda/funcionesArbolBinarioBusqueda.h"
#include "BibliotecaArbolBinarioBusqueda/ArbolBinarioBusqueda.h"
using namespace std;

//TODO: Esta cola guarda el numoer, NO GUARDA LOS NODOS: por restriccion del problema

struct NodoArbolBinarioBusqueda* busca(struct NodoArbolBinarioBusqueda* raiz, int dato) {
    if (raiz == nullptr) return nullptr;
    if (raiz->elemento.numero == dato) return raiz;
    else {
        if (raiz->elemento.numero > dato) {
            raiz = raiz->izquierda;
        }
        else {
            raiz = raiz->derecha;
        }
        return busca(raiz, dato);
    }
}

//como no es construccion, solo recorrido -> sin &
void diagonal(struct ArbolBinarioBusqueda arbol) {
    if (esArbolVacio(arbol)) return;

    struct Cola cola;
    construir(cola);
    struct NodoArbolBinarioBusqueda* ptr_arbol = arbol.raiz;

    while (ptr_arbol != nullptr) {
        //imprimo la raiz (que seria el derecha actalziado)
        cout<<ptr_arbol->elemento.numero<< " ";
        //la izquierdas se van encolando, Cuando las derechas terminen recien se desencolan
        if (ptr_arbol->izquierda != nullptr) {
            struct ElementoCola elemento_cola {ptr_arbol->izquierda->elemento.numero};
            encolar(cola, elemento_cola);
        }
        //las derechas se van vvolviendo raiz, hasta que no exista más hijos derechos
        if (ptr_arbol->derecha != nullptr) {
            ptr_arbol = ptr_arbol->derecha;
        }
        //cuando no hay mas hhijos dferechos, paso a desencolar los hijos izquierdos que se guardaron
        else {//derecha nullptr
            if (not esColaVacia (cola)) {//cuando ya no puedes pasar a la otra diagonal, ya no hay mas izquierda
                struct ElementoCola elemento_izquierda;
                elemento_izquierda = desencolar(cola);
                ptr_arbol = busca(arbol.raiz, elemento_izquierda.codigo);
            }else {
                ptr_arbol = nullptr; //break?
            }
        }
    }

}

int main() {
    struct ArbolBinarioBusqueda arbol;
    construir(arbol);

    insertar(arbol,{100} );
    insertar(arbol,{150} );
    insertar(arbol,{175} );
    insertar(arbol,{200} );
    insertar(arbol,{50} );
    insertar(arbol,{75} );
    insertar(arbol,{125} );
    insertar(arbol,{25} );
    insertar(arbol,{40} );
    diagonal(arbol);
    return 0;
}