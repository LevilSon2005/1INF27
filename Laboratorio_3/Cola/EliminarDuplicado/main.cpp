#include <iostream>
#include "BibliotecaCola/Cola.h"
#include "BibliotecaCola/funcionesCola.h"
using namespace std;

void EliminarUnDuplicado(struct Cola &cola) {
    int n=cola.longitud;
    struct ElementoCola elemento = cola.inicio->elemento;
    for (int i = 0; i < n-1; i++) {
        struct ElementoCola temporal = desencolar(cola);
        if (elemento.codigo != temporal.codigo) encolar(cola, temporal);
    }
}

void EliminarDuplicados(struct Cola &cola) {

    struct ElementoCola cabeza = cola.inicio->elemento;
    struct ElementoCola elemento = desencolar(cola);
    do {
        int n=cola.longitud;
        for (int i = 0; i < n; i++) {
            struct ElementoCola temporal = desencolar(cola);
            if (elemento.codigo != temporal.codigo) encolar(cola, temporal);
        }
        encolar(cola,elemento);
        imprimir(cola);
        elemento = desencolar(cola);
    }while (elemento.codigo != cabeza.codigo);
}

int main() {
    struct Cola cola;
    construir(cola);

    struct ElementoCola e1 {3};
    struct ElementoCola e2 {5};
    struct ElementoCola e3 {7};
    struct ElementoCola e4 {3};
    struct ElementoCola e5 {5};
    struct ElementoCola e6 {9};
    struct ElementoCola e7 {3};

    encolar(cola,e1);
    encolar(cola,e2);
    encolar(cola,e3);
    encolar(cola,e4);
    encolar(cola,e5);
    encolar(cola,e6);
    encolar(cola,e7);

    cout<<"Cola inicial: ";
    imprimir(cola);
    EliminarDuplicados(cola);
    // imprimir(cola);
    return 0;
}