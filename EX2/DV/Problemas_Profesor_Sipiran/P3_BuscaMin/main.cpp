#include <iostream>
using namespace std;

//TODO: 3. Un arreglo está rotado en algún punto desconocido. Encontrar el
// elemento mínimo del arreglo. Asumir que todos los elementos son
// distintos.
// Ejemplo:
// Entrada: {5, 6, 1, 2, 3, 4}
// Salida: 1

int min(int a, int b) {
    return a < b ? a : b;
}

int buscaMinimo(int* arreglo, int inicio, int fin) {
    if (inicio == fin) return arreglo[inicio];
    if (inicio > fin) return -1;

    int medio = (inicio+fin)/2;
    //Si estuvier ordenado el medio seria menor que el fin, pero si es lo contrario
    // entonces la ruptura(el elemento menor se encuentra a la derecha)
    if (arreglo[medio] > arreglo[fin]) {
        return buscaMinimo(arreglo, medio+1, fin);
    }else {//sino la ruptura(menor) esta a la izquierda
        return buscaMinimo(arreglo,inicio, medio);
    }
}

int main() {
    int arreglo[] =  {3, 4, 5, 6, 7, 1, 2};
    int n = sizeof(arreglo) / sizeof(arreglo[0]);

    int min = buscaMinimo(arreglo, 0, n-1);
    cout << min;
    return 0;
}