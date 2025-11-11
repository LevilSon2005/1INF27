#include <iostream>
#include <ostream>

#include "BibliotecaArbolBinario/funcionesArbolBinario.h"
#include "BibliotecaArbolBinario/ArbolBinario.h"

using namespace std;

/// LAB4 - 2022.2

//n: nivel
void insertaNivel(struct NodoArbolBinario* & nodo_raiz, int* pesos, int inicio, int fin) {
    if (inicio == fin) return;

    //Para insertar al lado izquierda
    struct ElementoArbolBinario elemento;
    elemento.estado =0;
    elemento.numero = pesos[inicio];
    struct NodoArbolBinario* nodo_izquierda;
    plantarNodoArbolBinario(nodo_izquierda, nullptr, elemento, nullptr);
    nodo_raiz->izquierda = nodo_izquierda;
    insertaNivel(nodo_raiz->izquierda, pesos, inicio+1, fin);

    //Para insertar al lado derecha
    elemento.estado = 1;
    elemento.numero = pesos[inicio];
    struct NodoArbolBinario* nodo_derecha;
    plantarNodoArbolBinario(nodo_derecha, nullptr, elemento, nullptr);
    nodo_raiz->derecha = nodo_derecha;
    insertaNivel(nodo_raiz->derecha, pesos, inicio+1, fin);

}

//Primero creamos el arbol, pero de manera recursivo
//Pero el primer nodo, la raiz, se crea de manera manual. Lo demás si de manera recursiva
void crearArbol(struct ArbolBinario &arbol, int* pesos, int n, int peso_max) {
    //crear Abol Vacio
    ArbolBinario arbolVacio;
    construir(arbolVacio); //se le pone nullptr al arbol vacio

    ElementoArbolBinario elemento {0,0};

    plantarArbolBinario(arbol, arbolVacio, elemento, arbolVacio );
    //el n, representa el nivel del AB y es uno más del indice <> primer nivel : indice 0
    insertaNivel(arbol.raiz, pesos,0, n );

}

//CONTADOR GLOBAL
int contador=0;

void calcula(struct NodoArbolBinario* ptr_arbol, int peso_max, int peso_parcial) {
    if (ptr_arbol == nullptr) return;

    int producto = ptr_arbol->elemento.estado * ptr_arbol->elemento.numero;
    peso_parcial += producto;

    if (ptr_arbol->izquierda == nullptr && ptr_arbol->derecha == nullptr) {
        if (peso_max == peso_parcial) contador++;
    }else {
        calcula(ptr_arbol->izquierda, peso_max, peso_parcial);
        calcula(ptr_arbol->derecha, peso_max, peso_parcial);
    }
}

int main() {

    ArbolBinario arbol;
    construir(arbol);

    int pesos[] = {10,50};
    int peso_max= 70;
    int n=sizeof(pesos)/sizeof(pesos[0]);

    crearArbol(arbol, pesos, n, peso_max);
    recorrerEnOrden(arbol);

    calcula(arbol.raiz, peso_max, 0);
    cout << "La cantidad de cromosomas : " << contador << endl;

    return 0;
}