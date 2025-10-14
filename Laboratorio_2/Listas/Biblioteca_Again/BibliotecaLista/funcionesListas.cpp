//
// Created by binny on 10/10/2025.
//

#include "funcionesListas.h"
#include <random>

void construir(struct Lista &listaTAD) {
    listaTAD.inicio=nullptr;
    listaTAD.fin=nullptr;
    listaTAD.longitud=0;
}

bool esListaVacia(const struct Lista &listaTAD) {
    return (listaTAD.inicio==nullptr and listaTAD.fin==nullptr);
}

void insertarAlInicio(struct Lista &listaTAD, const struct ElementoLista &elemento) {
    //CREAMOS NODO
    struct NodoLista* nuevo_nodo;
    nuevo_nodo = new NodoLista{};
    nuevo_nodo->elemento = elemento;
    nuevo_nodo->siguiente = nullptr;

    if (listaTAD.inicio==nullptr) {
        listaTAD.inicio = nuevo_nodo;
        listaTAD.fin = nuevo_nodo;
    }else {
        nuevo_nodo->siguiente = listaTAD.inicio;
        listaTAD.inicio = nuevo_nodo;
    }
    listaTAD.longitud++;
}

void insertarAlFinal(struct Lista &listaTAD, const struct ElementoLista &elemento) {
    //CREAMOS NUEVO NODO
    struct NodoLista* nuevo_nodo;
    nuevo_nodo = new NodoLista{};
    nuevo_nodo->elemento = elemento;
    nuevo_nodo->siguiente = nullptr;
    //
    if (listaTAD.inicio==nullptr) {
        listaTAD.inicio = nuevo_nodo;
        listaTAD.fin = nuevo_nodo;
    }else {
        // struct NodoLista* recorrido = listaTAD.inicio;
        // while (recorrido->siguiente) { //esto para en ultimo nodo y recorrido para en el nullptr
        //     recorrido = recorrido->siguiente;
        // }
        // recorrido->siguiente = nuevo_nodo;
        listaTAD.fin->siguiente = nuevo_nodo;
        listaTAD.fin = nuevo_nodo;
    }
    listaTAD.longitud++;
}

struct NodoLista * obtenerUltimoNodo(const struct Lista &listaTAD) {
    struct NodoLista* recorrido = listaTAD.inicio;
    while (recorrido->siguiente) {
        recorrido = recorrido->siguiente;
    }
    return recorrido;
}

void insertarEnOrden(struct Lista &listaTAD, const struct ElementoLista &elemento) {
    //CONSTRUIMOS EL NODO
    struct NodoLista* nuevo_nodo;
    nuevo_nodo = new NodoLista{};
    nuevo_nodo->elemento = elemento;
    nuevo_nodo->siguiente = nullptr;
    //

    if (esListaVacia(listaTAD)) {
        listaTAD.inicio = nuevo_nodo;
    }else {
        struct NodoLista* recorrido = listaTAD.inicio;
        struct NodoLista* anterior =  nullptr;

        while (recorrido) {
            if (recorrido->elemento.numero > elemento.numero) break;
            anterior = recorrido;
            recorrido = recorrido->siguiente;
        }
        nuevo_nodo->siguiente = recorrido;
        if (anterior!= nullptr) anterior->siguiente = nuevo_nodo;
        else listaTAD.inicio = nuevo_nodo;
    }
    listaTAD.longitud++;
}


void eliminaNodo(struct Lista &listaTAD, const struct ElementoLista &elemento) {
    struct NodoLista * anterior = nullptr;
    struct NodoLista * recorrido = listaTAD.inicio;
    /*Avanzo hasta encontrar el elemento*/
    /*Si no lo encuentra no elimina nada*/
    while ((recorrido != nullptr) and (recorrido->elemento.numero != elemento.numero)) {
        anterior = recorrido;
        recorrido = recorrido->siguiente;
    }

    if (recorrido != nullptr) {
        if (anterior == nullptr) /*Estoy al inicio de la lista*/
            listaTAD.inicio = recorrido->siguiente;
        else
            anterior->siguiente = recorrido->siguiente;
        delete recorrido; /*libera la memoria*/
    }
    listaTAD.longitud--;
}

void destruir(struct Lista & listaTAD) {
    /*recorrido apunta al inicio del tad*/
    struct NodoLista * recorrido = listaTAD.inicio;

    while (recorrido != nullptr) {
        /*NodoLista auxiliar que va servir para eliminar los NodoListas*/
        struct NodoLista * NodoListaAEliminar = recorrido;
        recorrido = recorrido->siguiente;
        delete NodoListaAEliminar;
    }
    /*la lista queda vacia*/
    listaTAD.inicio = nullptr;
    listaTAD.longitud = 0;
}

/*con const aquello que pasas no va cambiar, el compilador se da cuenta que es constante*/
void imprimir(const struct Lista & listaTAD) {

    if (esListaVacia(listaTAD)) {
        cout << "La lista esta vacia no se puede mostrar" << endl;
    } else {
        struct NodoLista * recorrido = listaTAD.inicio;
        int estaImprimiendoLaCabeza = 1;
        cout << "[";

        while (recorrido != nullptr) {
            /*Este artificio coloca las comas despuÃƒÂ©s de la cabeza*/
            if ( not estaImprimiendoLaCabeza)
                cout << ", ";
            estaImprimiendoLaCabeza = 0;
            cout << recorrido->elemento.numero;
            recorrido = recorrido->siguiente;
        }
        cout << "]" << endl;
    }
}
