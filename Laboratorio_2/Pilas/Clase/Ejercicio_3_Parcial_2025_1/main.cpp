#include <iostream>
#include "Biblioteca_Pilas/NodoPila.h"
#include "Biblioteca_Pilas/Pila.h"
#include "Biblioteca_Pilas/funcionesPila.h"

using namespace std;

/*Vamos a trabajar con dos pilas:
* En la pila principal, se van apilando (ingresando) los datos
* En la pila aux, de manera simultanea que se va apilando en la principal se halla el min:
* Cada vez que se apila se va preguntando el nuevo dato es mayor que la pila del aux
 */

struct nuevaPila {
    struct Pila principal;
    struct Pila aux;
};

void n_construir(struct nuevaPila &pila) {
    construir(pila.principal); //aca´los valores se apilan sin problema
    construir(pila.aux); //aqui se va a guardar el minimo historico, es decir, el menor de la pila
}

void n_apilar(struct nuevaPila &pila, struct ElementoPila dato) {
    apilar(pila.principal, dato);
    if (esPilaVacia(pila.aux) or dato.numero <= cima(pila.aux).numero){ //si el nuevo dato es menor que la cima
        apilar(pila.aux, dato); //apilamos el nodo del nuevo dato
    }else {
        apilar(pila.aux, cima(pila.aux)); //apilamos el nodo de la cima
    }
}

struct ElementoPila n_desapilar(struct nuevaPila &pila) {
    if (not esPilaVacia(pila.principal)) { // no podemos desapilar si está vacia
        struct ElementoPila elemento_guardado = desapilar(pila.principal);
        struct ElementoPila minimo = desapilar(pila.aux);
        return elemento_guardado;
    }
}

struct ElementoPila minimo(struct nuevaPila pila) {
    return cima(pila.aux);
}

int main() {
    struct nuevaPila pila;
    struct ElementoPila temporal; //el dato que va entrar en el nodo
    // temporal = {201809};

    n_construir(pila);
    temporal.numero = 201809;
    n_apilar(pila, temporal);
    temporal.numero = 202010;
    n_apilar(pila, temporal);
    temporal.numero = 201510;
    n_apilar(pila, temporal);
    temporal.numero = 202409;
    n_apilar(pila, temporal);

    cout<<minimo(pila).numero<<endl;
    imprimir(pila.principal);
    imprimir(pila.aux);
    cout<<n_desapilar(pila).numero<<endl;

    return 0;
}