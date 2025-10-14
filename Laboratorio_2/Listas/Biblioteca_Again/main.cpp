#include "BibliotecaLista/funcionesListas.h"
#include "BibliotecaLista/Lista.h"

void ordenar(struct Lista &lista) {
    if (esListaVacia(lista)) return;

    struct NodoLista *inicio_aux = nullptr;
    struct NodoLista *recorrido = lista.inicio;
    struct NodoLista *recorrido_2 = nullptr;

    while (recorrido) {
        recorrido_2 = recorrido;
        recorrido = recorrido->siguiente;

        if (inicio_aux == nullptr) {
            inicio_aux = recorrido_2;
            recorrido_2->siguiente = nullptr;
        }
        else {
            struct NodoLista *anterior = nullptr;
            struct NodoLista *recorrido_ordenado = inicio_aux;

            while (recorrido_ordenado) {
                if (recorrido_2->elemento.numero < recorrido_ordenado->elemento.numero) break;
                anterior = recorrido_ordenado;
                recorrido_ordenado = recorrido_ordenado->siguiente;
            }

            if (anterior == nullptr) {
                recorrido_2->siguiente = inicio_aux;
                inicio_aux = recorrido_2;
            } else {
                recorrido_2->siguiente = recorrido_ordenado;
                anterior->siguiente = recorrido_2;
            }
        }
    }

    lista.inicio = inicio_aux;

    // Actualizar el fin
    lista.fin = lista.inicio;
    if (lista.fin) {
        while (lista.fin->siguiente) {
            lista.fin = lista.fin->siguiente;
        }
    }
}

void fusionarLista(struct Lista &lista1, struct Lista &lista2) {
    // Caso 1: lista2 vacía
    if (esListaVacia(lista2)) return;

    // Caso 2: lista1 vacía
    if (esListaVacia(lista1)) {
        lista1.inicio = lista2.inicio;
        lista1.fin = lista2.fin;
        lista1.longitud = lista2.longitud;
        lista2.inicio = lista2.fin = nullptr;
        lista2.longitud = 0;
        return;
    }

    // Caso directo: todos los elementos de lista1 son menores
    if (lista1.fin->elemento.numero < lista2.inicio->elemento.numero) {
        lista1.fin->siguiente = lista2.inicio;
        lista1.fin = lista2.fin;
        lista1.longitud += lista2.longitud;
        lista2.inicio = lista2.fin = nullptr;
        lista2.longitud = 0;
    }
    // Caso directo: todos los elementos de lista2 son menores
    else if (lista2.fin->elemento.numero < lista1.inicio->elemento.numero) {
        lista2.fin->siguiente = lista1.inicio;
        lista1.inicio = lista2.inicio;
        lista1.longitud += lista2.longitud;
        lista2.inicio = lista2.fin = nullptr;
        lista2.longitud = 0;
    }
    // Caso: mezcla necesaria (similar al del profesor)
    else {
        NodoLista *nini, *nfin;
        nini = nullptr;
        nfin = nullptr;

        while (!esListaVacia(lista1) && !esListaVacia(lista2)) {
            if (lista1.inicio->elemento.numero < lista2.inicio->elemento.numero) {
                if (nini == nullptr) {
                    nini = lista1.inicio;
                    nfin = lista1.inicio;
                } else {
                    nfin->siguiente = lista1.inicio;
                    nfin = lista1.inicio;
                }
                lista1.inicio = lista1.inicio->siguiente;
                nfin->siguiente = nullptr; // Importante: desconectar
            } else {
                if (nini == nullptr) {
                    nini = lista2.inicio;
                    nfin = lista2.inicio;
                } else {
                    nfin->siguiente = lista2.inicio;
                    nfin = lista2.inicio;
                }
                lista2.inicio = lista2.inicio->siguiente;
                nfin->siguiente = nullptr; // Importante: desconectar
            }
        }

        // Agregar elementos restantes de lista1
        if (!esListaVacia(lista1)) {
            nfin->siguiente = lista1.inicio;
            nfin = lista1.fin;
        }

        // Agregar elementos restantes de lista2
        if (!esListaVacia(lista2)) {
            nfin->siguiente = lista2.inicio;
            nfin = lista2.fin;
        }

        // Actualizar lista1
        lista1.inicio = nini;
        lista1.fin = nfin;

        // Actualizar longitud
        lista1.longitud += lista2.longitud;

        // Limpiar lista2
        lista2.inicio = lista2.fin = nullptr;
        lista2.longitud = 0;
    }
}

int main() {
    struct Lista lista1{};
    construir(lista1);

    struct ElementoLista elemento;
    elemento.numero = 15;
    insertarAlInicio(lista1, elemento);
    elemento.numero = 19;
    insertarAlFinal(lista1, elemento);
    elemento.numero = 9;
    insertarAlFinal(lista1, elemento);
    elemento.numero = 12;
    insertarAlFinal(lista1, elemento);
    imprimir(lista1);
    ordenar(lista1);
    imprimir(lista1);

    struct Lista lista2{};
    construir(lista2);
    elemento.numero = 17;
    insertarAlInicio(lista2, elemento);
    elemento.numero = 10;
    insertarAlFinal(lista2, elemento);
    elemento.numero = 6;
    insertarAlFinal(lista2, elemento);
    elemento.numero = 13;
    insertarAlFinal(lista2, elemento);
    ordenar(lista2);
    imprimir(lista2);

    fusionarLista(lista1, lista2);
    imprimir(lista1);

    return 0;
}