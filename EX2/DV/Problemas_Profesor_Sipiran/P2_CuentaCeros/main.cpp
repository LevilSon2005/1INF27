#include <iostream>
using namespace std;

//Todo: Dado un arreglo de 0’s y 1’s el cual tiene todos los 1’s primero
// seguido de todos los 0’s. Encontrar el número de 0’s.
// Ejemplos:
// Entrada: {1, 1, 1, 0, 0, 0, 0}
// Output: 4
// Entrada: {1, 1, 1, 1, 1}
// Salida: 0

int cuentaCeros(int* arreglo, int inicio, int fin) {
    if (inicio == fin) {
        if (arreglo[inicio] == 0) return 1;
        else return 0;
    }
    if (inicio > fin) return 0;

    int medio = (inicio+fin)/2;
    if (arreglo[medio] ==1 ) {
        return cuentaCeros(arreglo, medio+1, fin);
    }
    else {
        return cuentaCeros(arreglo, inicio, medio-1) + (fin-medio +1);
    }

}

int main() {
    int arreglo[] = {1, 1, 0,0,0,0,0,0,0};
    int n = sizeof(arreglo) / sizeof(arreglo[0]);

    int cant_ceros = cuentaCeros(arreglo, 0, n-1);
    cout<<"La cantidad de ceros es : "<<cant_ceros<<endl;
    return 0;
}