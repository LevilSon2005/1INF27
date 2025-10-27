#include <iostream>
#include "BibliotecaCola/Cola.h"
#include "BibliotecaCola/funcionesCola.h"
using namespace std;

void invertir(struct Cola &cola) {
    if (esColaVacia(cola)) return;
    struct ElementoCola aux = desencolar(cola);
    invertir(cola);
    encolar(cola,aux);
}

int main() {
    struct Cola cola;
    construir(cola);

    struct ElementoCola e1 {1};
    struct ElementoCola e2 {2};
    struct ElementoCola e3 {3};
    struct ElementoCola e4 {4};
    struct ElementoCola e5 {5};

    encolar(cola,e1);
    encolar(cola,e2);
    encolar(cola,e3);
    encolar(cola,e4);
    encolar(cola,e5);

    cout<<"Cola inicial: ";
    imprimir(cola);
    cout<<"Cola Invertida: ";
    invertir(cola);
    imprimir(cola);
    return 0;
}