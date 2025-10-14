//
// Created by binny on 09/10/2025.
//

#include "FuncionesPilas.hpp"

void construir(struct Pila &pila) {
    pila.inicio = nullptr;
    pila.longitud = 0;
}

bool esPilaVacia(const struct Pila &pila) {
    return (pila.inicio == nullptr);
}

int longitud(const struct Pila &pila) {
    return pila.longitud;
}

struct ElementoPila cima(const struct Pila &pila) {
    if (esPilaVacia(pila)) cout << "Pila Vacia" << endl;
    else return pila.inicio->elemento;
}

void apilar(class Pila& pila, const struct ElementoPila& elemento) {
    //CCREAMOS NUEVO NODO
    struct NodoPila* nuevo;
    nuevo = new struct NodoPila;
    nuevo->elemento = elemento;
    nuevo->siguiente=nullptr;

    //CONECTAR
    nuevo->siguiente = pila.inicio;
    pila.inicio = nuevo;
    pila.longitud++;
}

struct ElementoPila desapilar(class Pila& pila) {
    struct ElementoPila elemento_retorno;
    elemento_retorno = cima(pila);

    struct NodoPila* nodo_sale;
    nodo_sale = pila.inicio;
    pila.inicio = pila.inicio->siguiente;
    delete nodo_sale;
    pila.longitud--;

    return elemento_retorno;
}

void imprimir(const struct Pila &pila) {
    if (esPilaVacia(pila)) cout << "Pila Vacia" << endl;
    else {
        struct NodoPila *recorrido = pila.inicio;
        int estaImprimiendoLaCabeza = 1;
        cout << "[";

        while (recorrido != nullptr) {
            /*Este artificio coloca las comas después del inicio*/
            if (not estaImprimiendoLaCabeza)
                cout << ", ";
            estaImprimiendoLaCabeza = 0;
            cout << recorrido->elemento.numero;
            recorrido = recorrido->siguiente;
        }
        cout << "]" << endl;
    }
}
