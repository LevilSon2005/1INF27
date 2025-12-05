#include <iostream>
#include "BibliotecaArbolBinario/funcionesArbolBinario.h"
#include "BibliotecaArbolBinario/ArbolBinario.h"
using namespace std;

void insertarPorNivel_recursivo(struct NodoArbolBinario* &nodo ,int valor, int bit) {
    if (esNodoVacio(nodo)) { //cuando lleguen al ultimo nivel
        struct ElementoArbolBinario elemento{valor, bit};
        plantarNodoArbolBinario(nodo,nullptr, elemento, nullptr);
        return;
    }
    insertarPorNivel_recursivo(nodo->izquierda,valor,0);
    insertarPorNivel_recursivo(nodo->derecha,valor,1);
}

void insertarPorNivel(struct ArbolBinario &arbol,int valor) {
    insertarPorNivel_recursivo(arbol.raiz , valor, 0);
}

void construirAB(struct ArbolBinario &arbol, int* arreglo, int n) {
    struct ArbolBinario arbolVacio;
    construir(arbolVacio);

    struct ElementoArbolBinario elemento{0,0};
    plantarArbolBinario(arbol, arbolVacio, elemento, arbolVacio);

    for (int i=0;i<n;i++) {
        insertarPorNivel(arbol,arreglo[i]);
    }
}

void HallarSoluciones(struct ArbolBinario arbol, int peso_max) {

}

int main() {
    int arreglo[] = {10,50,20,30,40};
    int n = sizeof(arreglo)/sizeof(arreglo[0]);
    struct ArbolBinario arbol;
    construirAB(arbol, arreglo, n );

    int peso_maximo = 70;
    recorrerEnOrden(arbol);
    HallarSoluciones(arbol, peso_maximo);
    return 0;
}