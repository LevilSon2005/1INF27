#include <iostream>
using namespace std;
#include "BibliotecaLista/Lista.h"
#include "BibliotecaLista/funcionesLista.h"

void marcar(struct Lista &lista) {
    struct NodoLista * recorrido = lista.inicio;
    while (recorrido) {
        if ( recorrido->siguiente != nullptr
            and recorrido->elemento.prioridad == recorrido->siguiente->elemento.prioridad) {
            recorrido->elemento.enGrupo = true;
            recorrido->siguiente->elemento.enGrupo = true;
            recorrido =  recorrido->siguiente->siguiente;
        }
        else {
            recorrido = recorrido->siguiente;
        }
    }
}

void imprimir_consecutivas(struct Lista lista) {
    if (esListaVacia(lista)) {
        cout << "La lista esta vacia no se puede mostrar" << endl;
    } else {
        struct NodoLista * recorrido = lista.inicio;
        int estaImprimiendoLaCabeza = 1;
        cout << "[";

        while (recorrido != nullptr) {
            /*Este artificio coloca las comas despuÃ©s de la cabeza*/
            if ( not estaImprimiendoLaCabeza)
                cout << ", ";
            estaImprimiendoLaCabeza = 0;
            cout << recorrido->elemento.codigo<<"-"<<recorrido->elemento.enGrupo;
            recorrido = recorrido->siguiente;

        }
        cout << "]" << endl;
    }
}

/*
 * Sublista2 vacia <> last1 = last2;
 * Sublista1 vacia <> XXXXXXXXXXXXXXXXXXXXXXXXX
 */


void agregarFinalSubLista (struct NodoLista* actual, struct NodoLista*& inicio, struct NodoLista*& fin) {
    //todo: primer nodo de la lista
    if (inicio == nullptr) {
        inicio = actual;
        fin = actual;
    }
    //todo: insertarAlFinal
    else {
        fin->siguiente = actual;
        fin = actual;
    }
}

void enlazarSubListas(struct NodoLista* inicio_A,struct NodoLista* fin_A,
                      struct NodoLista* inicio_grupos,struct NodoLista* fin_grupos,
                       struct NodoLista*  inicio_aislado,struct NodoLista*  fin_aislado,
                       struct Lista&  lista) {
    lista.inicio = inicio_A;
    fin_A->siguiente = inicio_grupos;
    fin_grupos->siguiente = inicio_aislado;
}

void reordenar(struct Lista &lista) {
    struct NodoLista* inicio_A = nullptr;
    struct NodoLista* fin_A = nullptr;

    struct NodoLista* inicio_grupos=nullptr;
    struct NodoLista* fin_grupos=nullptr;

    struct NodoLista* inicio_aislado = nullptr;
    struct NodoLista* fin_aislado = nullptr;

    struct NodoLista* recorrido = lista.inicio;
    struct NodoLista * actual = nullptr;
    while (recorrido) {
        actual = recorrido;
        recorrido =  recorrido->siguiente; //este avanza de una vez, pero utilizo recorrido_2 para los enlaces

        if (actual->elemento.prioridad == 'A') agregarFinalSubLista (actual, inicio_A, fin_A);
        else {//si es 'B' o 'C'
            if (actual->elemento.enGrupo == true) {
                agregarFinalSubLista (actual, inicio_grupos, fin_grupos);
                //avanzo uno más para insertar los dos seguidos
                actual = recorrido;
                recorrido = recorrido->siguiente;
                agregarFinalSubLista (actual, inicio_grupos, fin_grupos);
            }
            else agregarFinalSubLista (actual, inicio_aislado, fin_aislado);
        }
    }

    enlazarSubListas(inicio_A,fin_A,inicio_grupos,fin_grupos, inicio_aislado, fin_aislado,lista);
}

void imprimir_contenido(struct Lista &lista) {
    if (esListaVacia(lista)) {
        cout << "La lista esta vacia no se puede mostrar" << endl;
    } else {
        struct NodoLista * recorrido = lista.inicio;

        while (recorrido != nullptr) {
            /*Este artificio coloca las comas despuÃ©s de la cabeza*/
            cout << recorrido->elemento.codigo<<" - "<<recorrido->elemento.cantidadUnidades <<" - "<<recorrido->elemento.prioridad<<endl;
            recorrido = recorrido->siguiente;

        }
    }
}

int main() {
    struct Lista lista;
    construir(lista);

    struct ElementoLista l1 = {1,10,'B'};
    struct ElementoLista l2 = {2,20,'A'};
    struct ElementoLista l3 = {3,15,'B'};
    struct ElementoLista l4 = {4,12,'B'};
    struct ElementoLista l5 = {5,5,'C'};
    struct ElementoLista l6 = {6,6,'A'};
    struct ElementoLista l7 = {7,8,'C'};
    struct ElementoLista l8 = {8,4,'C'};
    struct ElementoLista l9 = {9,2,'B'};

    insertarAlFinal(lista, l1);
    insertarAlFinal(lista, l2);
    insertarAlFinal(lista, l3);
    insertarAlFinal(lista, l4);
    insertarAlFinal(lista, l5);
    insertarAlFinal(lista, l6);
    insertarAlFinal(lista, l7);
    insertarAlFinal(lista, l8);
    insertarAlFinal(lista, l9);

    cout<<"Lista incial: ";
    imprimir(lista);
    cout<<"Lista con grupos: ";
    marcar(lista);
    imprimir_consecutivas(lista);
    reordenar(lista);
    cout<<"-----RESULTADOS: ------------"<<endl;
    imprimir_contenido(lista);
    return 0;
}