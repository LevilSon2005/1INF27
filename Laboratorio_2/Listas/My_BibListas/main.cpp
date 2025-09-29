#include "my_bibliotecaLista/BibliotecaLista.hpp"




int main() {
    struct Lista lista1;
    construir(lista1);
    if (esListaVacia(lista1)) cout<<"Al menos se incializo"<<endl;

    struct ElementoLista elemento;
    elemento.codigo = 3;
    insertarAlInicio(lista1, elemento);
    imprimir(lista1);

    elemento.codigo = 5;
    insertarAlInicio(lista1, elemento);
    imprimir(lista1);

    elemento.codigo = 2;
    insertarAlFinal(lista1, elemento);
    imprimir(lista1);

    elemento.codigo = 13;
    insertarAlFinal(lista1, elemento);
    imprimir(lista1);

    struct NodoLista* nodo = obtenerUltimoNodo(lista1);
    cout<<nodo->elemento.codigo<<endl;

    struct Lista lista2;
    construir(lista2);

    elemento.codigo = 5;
    insertarEnOrden(lista2, elemento);
    imprimir(lista2);

    elemento.codigo = 4;
    insertarEnOrden(lista2, elemento);
    imprimir(lista2);

    elemento.codigo = 9;
    insertarEnOrden(lista2, elemento);
    imprimir(lista2);

    eliminarNodo(lista2, elemento);
    imprimir(lista2);

    destruir(lista2);
    imprimir(lista2);
    return 0;
}