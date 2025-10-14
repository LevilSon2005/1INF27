#include "BibliotecaPila/funcionesPila.h"
#include "BibliotecaPila/NodoPila.h"
#include "BibliotecaPila/Pila.h"
#include <iostream>
#include <iomanip>
using namespace std;

void PasaPila(struct Pila &pila1, struct Pila& pila2) {
    while (!esPilaVacia(pila1)) {
        int n=0;
        struct ElementoPila aux;
        while (true) {
            aux =  desapilar(pila1); //de esta manera el ultimo elemento no se apila en pila 2 y se guarda en aux
            if (esPilaVacia(pila1)) break;
            apilar(pila2, aux);
            n++; //cantidad de movimientos auxiliares para sacar el ultimo elemento, esa misma cantidad se va a devolver
        }

        //quiero apilar mi 3 en pila2, pero está lleno así que lo vacio
        while (n>0) {
            struct ElementoPila elemento_devolver;
            elemento_devolver = desapilar(pila2);
            apilar(pila1, elemento_devolver);
            n--;
        }

        //Ahora pila 2 se encuentra vacia de nuevo y ya puedo poner el elemento que guarde
        apilar(pila2, aux);
    }
}

void PilaRecursiva(struct Pila& pila1, struct Pila& pila2) {
    struct ElementoPila aux;
    //caos base
    if (esPilaVacia(pila1)) return;
    aux = desapilar(pila1);
    PilaRecursiva(pila1, pila2);
    apilar(pila2, aux);
}


int main() {
    struct Pila pila;
    struct Pila pilaNuevo;
    construir(pila);
    construir(pilaNuevo);
    struct ElementoPila elemento;
    elemento.numero = 3;
    apilar(pila,elemento);
    elemento.numero = 20;
    apilar(pila,elemento);
    elemento.numero = 12;
    apilar(pila,elemento);
    elemento.numero = 8;
    apilar(pila,elemento);
    cout<<"Pila inicial: ";
    imprimir(pila);
    /*cout<<"------------"<<endl;
    PasaPila(pila, pilaNuevo);
    cout<<endl<<"Pila 1: ";
    imprimir(pila);
    cout<<"Pila 2: ";*/
    PilaRecursiva(pila, pilaNuevo);
    cout<<"Pila nueva: ";
    imprimir(pilaNuevo);
    return 0;
}