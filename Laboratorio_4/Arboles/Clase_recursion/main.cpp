#include <iostream>
#include "BibliotecaArbolBinario/funcionesArbolBinario.h"
#include "BibliotecaArbolBinario/ArbolBinario.h"
#include "BibliotecaCola/funcionesCola.h"
#include "BibliotecaCola/Cola.h"
using namespace std;

struct NodoArbolBinario* buscarElementoEnAB(struct ArbolBinario arbol, int dato) {
    if (arbol.raiz == nullptr) return nullptr;
    else
        if (arbol.raiz->elemento.numero == dato) return arbol.raiz;
        else
            if (arbol.raiz->elemento.numero < dato)
}

void amplitud (struct ArbolBinario arbol){

    if (esArbolVacio(arbol)) return;

    struct NodoArbolBinario * aux; //con esto voy a hacer el recorrido
    aux = arbol.raiz;
    struct ElementoArbolBinario elementoArbol;
    elementoArbol = aux->elemento;

    struct Cola cola;
    construir(cola);
    struct ElementoCola elementoCola;
    elementoCola.codigo = elementoArbol.numero;
    encolar(cola, elementoCola); //inicialmente el primer elemento esta en cola

    while (!esColaVacia(cola)){
        elementoCola = desencolar(cola);
        cout << elementoCola.codigo<<" ";
        //ahora el unico elemento de la cola se desencolo e imprimio. EL nodo aux se perdió
        //Asi que vamos a hacer una funcion que busque

    }

}

int main() {

    return 0;
}