#include "Utils.hpp"
#include "Bib_ABB/funcionesABB.hpp"
#include "Bib_ABB/ABB.hpp"


int main() {
    struct ABB arbol;
    construir(arbol);

    /*
     *          8
     *         /  \
     *        7    10
     *       / \   / \
     *      1   N 9   20
     *     /\  /\
     *      5
     *     /\
     *    2 9
     */

    insertar(arbol, {8});
    insertar(arbol, {7});
    insertar(arbol, {1});
    insertar(arbol, {5});
    insertar(arbol, {6});
    insertar(arbol, {10});
    insertar(arbol, {2});
    insertar(arbol, {9});

    //todo: imprimir por amplitud de izquierda a derecha (ITERATIVO) -> COLA
    imprimir_amplitud_ID_Iterativo(arbol);
    cout<<endl;
    //todo: imprimir por amplitud de izq a der - con enter x c/nivel (ITERATIVO) -> COLA Y FOR
    imprimir_amplitud_ID_Iterativo_enter(arbol);
    //todo: imprimir por amplitud desde las hojas hacia la raiz.( de derecha a izquierda)-> COLA Y PILA
    imprimir_amplitud_reves(arbol);

    //TODO: IMPRESION DFS ITERATIVO -> PILAS
    //todo: impresión pre-orden
    cout<<"PreOrden: ";
    imprimir_pre_orden_iterativo(arbol);


    return 0;
}