//Fecha:  sábado 06 Setiembre 2025 
//Autor: Ana Roncal

#include <iostream>
#include "Cola.h"
#include "funcionesCola.h"
using namespace std;

void construir(struct Cola & colaTAD){
    colaTAD.inicio = nullptr;
    colaTAD.fin = nullptr;
    colaTAD.last1=nullptr;
    colaTAD.longitud1=0;
    colaTAD.longitud2 =0;
    colaTAD.longitud = 0;
}

/*devuelve la longitud de la cola*/
int longitud(const struct Cola & colaTAD) {
    return colaTAD.longitud1+colaTAD.longitud2;
}

void encolar(struct Cola &colaTAD, const struct ElementoCola & elemento){
    struct NodoCola *nuevo;
    nuevo = new NodoCola{};
    nuevo->elemento = elemento;
    if(esColaVacia(colaTAD)){
        colaTAD.inicio = nuevo;
        colaTAD.fin = nuevo;
    }
    else {
        colaTAD.fin->siguiente = nuevo;
        colaTAD.fin = nuevo;
    }
    colaTAD.longitud++;
}

struct ElementoCola desencolar(struct Cola & colaTAD){
    struct NodoCola * pSale;
    struct ElementoCola elemento;
    pSale = colaTAD.inicio;
    colaTAD.inicio = colaTAD.inicio->siguiente;
    elemento = pSale->elemento;
    colaTAD.longitud--;
    delete pSale;
    return elemento;
}

bool esColaVacia(const struct Cola & colaTAD){
    return colaTAD.inicio == nullptr;
}

void imprimir(const struct Cola & colaTAD) {
    if (esColaVacia(colaTAD)) {
        cout << "La cola esta vacia no se puede mostrar" << endl;
    } else {
        struct NodoCola * recorrido = colaTAD.inicio;
        int estaImprimiendoLaCabeza = 1;
        cout << "[";

        while (recorrido != nullptr) {
            /*Este artificio coloca las comas despues del inicio*/
            if ( not estaImprimiendoLaCabeza)
                cout << ", ";
            estaImprimiendoLaCabeza = 0;
            cout << recorrido->elemento.codigo;
            recorrido = recorrido->siguiente;
        }
        cout << "]" << endl;
    }
}

struct NodoCola* nodo(struct ElementoCola e) {
    struct NodoCola * nuevo;
    nuevo = new NodoCola;
    nuevo->elemento = e;
    nuevo->siguiente = nullptr;
    return nuevo;
}

//todo :se inserta el nodo nuevo despues del nodo p
// como es un insertarDespues se analiza si es ese nuevo_nodo es final de lista siempre
void insertarDespues(struct Cola &cola,struct NodoCola* p,struct NodoCola* nuevo) {
    if (p == nullptr) {
        //insertar al inicio
        nuevo->siguiente = cola.inicio;
        cola.inicio = nuevo;
        if (cola.fin ==  nullptr) cola.fin = nuevo;
    }
    else {
        nuevo->siguiente  = p->siguiente; //por si no es necesariamente al final
        p->siguiente = nuevo;
        if (cola.fin == p) cola.fin = nuevo;
    }
}

void encolarPrioridad(struct Cola &cola, struct ElementoCola e, int prioridad) {
    struct NodoCola * nuevo = nodo(e);
    if (prioridad == 1) {
        //todo: Existe cola 1
        if (cola.last1 != nullptr) {
            insertarDespues(cola,cola.last1,nuevo);
            cola.last1 = nuevo;
            //todo: No Existe cola 1 - insertarInicio
        }else {
            insertarDespues(cola,nullptr, nuevo);
            cola.last1 = nuevo;
        }
    }

    //la ultima cola no se actualiza el separador, porque ya es automatico con inse3rtarDespues
    if (prioridad == 2) {
        //todo: Existe cola2
        if (cola.fin != nullptr) {
            insertarDespues(cola, cola.fin, nuevo);
        }
        //todo: No existe cola2 - insertarIncio
        else {
            insertarDespues(cola, nullptr, nuevo);
        }
    }
}