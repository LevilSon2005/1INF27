#include <iostream>
#include <cstring>
#include "BibliotecaCola/Cola.h"
#include "BibliotecaCola/funcionesCola.h"
using namespace std;

///Primera Cola: Menores de edad
///
///Segnda Cola: Mayores de edad  (edad>=18)
///
///Codigo <> Edad

int prioridad(char* cadena) {
    if(strcmp(cadena, "Primera")==0) return 1;
    else return 2;
}

void insertarEnPrimeraCola(struct NodoCola* nuevo_nodo, struct Cola  &cola) {
    //todo: primer nodo en la cola total
    if (esColaVacia(cola)) {
        cola.inicio = nuevo_nodo;
        cola.fin = nuevo_nodo;
        cola.last1 = nuevo_nodo;
        cola.longitud_1++;
        return;
    }

    //todo: si solo existe cola2 - primer nodo para cola1
    if (cola.last1==nullptr) {
        //se debe hacer un insertar al inicio - Ultima vez que se actualiza inicio
        nuevo_nodo->siguiente = cola.inicio;
        cola.inicio = nuevo_nodo;
        cola.last1 = nuevo_nodo;
        cola.longitud_1++;
        return;
    }

    //todo: si existe cola1
    if (cola.last1 != nullptr) {
        //todo: si solo existe cola1
        if(cola.last1  == cola.fin) {
            //un insertar al final con last1 y se actualiza el fin
            cola.last1->siguiente = nuevo_nodo;
            cola.last1 = nuevo_nodo;
            cola.fin = nuevo_nodo;
        }
        //todo: si existe cola1 y existe cola2
        else {
            //insertar al final con last1 y conectar con el primero de la cola 2
            nuevo_nodo->siguiente=cola.last1->siguiente;
            cola.last1->siguiente=nuevo_nodo;
            cola.last1 = nuevo_nodo;
        }
    }
    cola.longitud_1++;
}


void insertarEnSegundaCola(struct NodoCola * nuevo_nodo, struct Cola &cola) {
    //todo: el primer nodo para toda la cola total
    if (esColaVacia(cola)) {
        cola.inicio = nuevo_nodo;
        cola.fin = nuevo_nodo;
        cola.longitud_2++;
        return;
    }

    //todo: solo existe la cola1 - primer nodo para cola2
    if (cola.last1 == cola.fin) {
        //inserta al final despues del last1 - unica vez que se actualiza el fin
        cola.last1->siguiente = nuevo_nodo;
        cola.fin = nuevo_nodo;
        cola.longitud_2++;
        return;
    }

    //todo: existe cola2
    if (cola.last1 != cola.fin) {
        //todo: solo existe cola2
        if (cola.last1 ==nullptr) {
            //insertar al final
            cola.fin->siguiente = nuevo_nodo;
            cola.fin = nuevo_nodo;
        }
        //todo: existe cola1 y existe cola2
        else {
            cola.fin->siguiente =nuevo_nodo;
            cola.fin = nuevo_nodo;
        }
    }
    cola.longitud_2++;
}

void encolarPrioridades(struct ElementoCola elemento,struct Cola  &colaPrioridad, int prioridad) {

    //todo: construimos el nodo
    struct NodoCola* nuevo_nodo;
    nuevo_nodo =  new struct NodoCola;
    nuevo_nodo->elemento = elemento;
    nuevo_nodo->siguiente=nullptr;

    if (prioridad==1) insertarEnPrimeraCola(nuevo_nodo, colaPrioridad);

    if (prioridad==2) insertarEnSegundaCola(nuevo_nodo, colaPrioridad);
}

int main() {
    struct Cola colaPrioridad;
    construir(colaPrioridad);

    struct ElementoCola a = {25,"Segunda"};
    struct ElementoCola b = {12,"Primera"};
    struct ElementoCola c = {22,"Segunda"};
    struct ElementoCola d = {34,"Segunda"};
    struct ElementoCola e = {16,"Primera"};
    struct ElementoCola f = {15,"Primera"};

    encolarPrioridades(a, colaPrioridad, prioridad(a.nombre));
    encolarPrioridades(b, colaPrioridad, prioridad(b.nombre));
    encolarPrioridades(c, colaPrioridad, prioridad(c.nombre));
    encolarPrioridades(d, colaPrioridad, prioridad(d.nombre));
    encolarPrioridades(e, colaPrioridad, prioridad(e.nombre));
    encolarPrioridades(f, colaPrioridad, prioridad(f.nombre));

    imprimir(colaPrioridad);
    return 0;
}