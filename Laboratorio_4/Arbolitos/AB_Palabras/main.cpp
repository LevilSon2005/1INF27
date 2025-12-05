#include <iostream>
#include "BibliotecaArbolBinario/funcionesArbolBinario.h"
#include "BibliotecaArbolBinario/ArbolBinario.h"
using namespace std;

int main() {
   struct ArbolBinario arbol[19], arbolVacio;
    construir(arbolVacio);
    for (int i=0; i<19; i++) construir(arbol[i]);

    //nivel 5
    plantarArbolBinario(arbol[0], arbolVacio, {'O'},arbolVacio);
    plantarArbolBinario(arbol[1], arbolVacio, {'S'},arbolVacio);
    plantarArbolBinario(arbol[2], arbolVacio, {'S'},arbolVacio);

    //nivel 4
    plantarArbolBinario(arbol[3], arbol[0], {'A'}, arbolVacio);
    return 0;
}