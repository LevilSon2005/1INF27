#include <iostream>
#include "BibliotecaLista/funcionesLista.h"
#include "BibliotecaLista/Lista.h"
#include "BibliotecaPila/funcionesPila.h"
#include "BibliotecaPila/Pila.h"
using namespace std;

/// IZQUIERDA: ultimo valor de la lista - DERECHA: valor del producto que se mueve

void EmpilarOrdenado(struct Pila &pila, struct ElementoPila elementoPila,
                    struct Pila& pilaA, struct Pila &pilaB, struct Pila &pilaC) {

    if (esPilaVacia(pila)) apilar(pilaA, elementoPila);
    else {
        struct ElementoPila tope = cima(pilaA);
        if (elementoPila.peso <= tope.peso) apilar(pilaA, elementoPila);
        else {

            while (tope.peso >= elementoPila.peso){
                apilar(pilaC, tope);
                tope = cima(pilaA);
                if (elementoPila.peso<tope.peso) {
                    apilar(pilaA, elementoPila);
                    apilar(pilaA, desapilar(pilaC));
                }
                else {
                    apilar(pilaB, desapilar(pilaA));
                    apilar(pilaB, desapilar(pilaC));
                }
            }

        }
    }
}

void ponerProductos(struct Pila &pila, struct Lista &lista) {

    struct Pila pilaA, pilaB, pilaC;
    construir(pilaA);
    construir(pilaB);
    construir(pilaC);
    int izquierda =0, derecha=0;
    int n_lista = lista.longitud;
    struct ElementoLista eliminar;

    //para cada elemento de la lista
    for (int i=0;i<n_lista;i++) {
        //se busca el ultimo nodo
        struct NodoLista* recorrido = lista.inicio;
        while (recorrido->siguiente) {
            recorrido = recorrido->siguiente;
        }
        eliminar = recorrido->elemento;
        izquierda = eliminar.peso;
        struct ElementoPila elementoPila {izquierda,recorrido->elemento.prioridad};
        eliminaNodo(lista,eliminar);
        EmpilarOrdenado(pila, elementoPila, pilaA, pilaB, pilaC);
    }

    imprimir(pilaA);
}

#define MAX_LISTA 7
int main() {

    struct Pila pila;
    construir(pila);

    struct Lista lista;
    construir(lista);

    struct ElementoLista productos[MAX_LISTA]={
        {1,100},
        {2,200},
        {2,50},
        {1,150},
        {1,200},
        {2,100},
        {1,50}
    };
    for (int i=0;i<MAX_LISTA;i++) {
        insertarAlFinal(lista, productos[i]);
    }
    imprimir(lista);

    ponerProductos(pila, lista);
    return 0;
}