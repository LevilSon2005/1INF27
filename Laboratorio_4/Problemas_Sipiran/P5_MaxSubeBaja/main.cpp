#include <iostream>
using namespace std;

/// 5. Dado un arreglo de enteros el cual primero crece y luego decrece.
/// Encontrar el máximo valor en el arreglo.
/// Ejemplo:
/// Entrada:{8, 10, 20, 80, 100, 200, 400, 500, 3, 2, 1}
/// Salida: 500

int encontrarMaxSubeBaja(int *arreglo, int inicio, int fin) {
    if (inicio == fin) return arreglo[inicio];
    if (inicio > fin) return -1;

    int medio = (inicio + fin) / 2;

    if (arreglo[medio+1] < arreglo[medio]) {
        return encontrarMaxSubeBaja(arreglo, inicio, medio);
    }
    //todo: cuando el siguiente todavia sigue creciendo
    else {
        return encontrarMaxSubeBaja(arreglo, medio+1, fin);
    }
}

int main() {
    int arreglo[] = {8, 10, 20, 80, 100, 200, 800, 900, 3, 2, 1};
    int n = sizeof(arreglo) / sizeof(arreglo[0]);

    int max = encontrarMaxSubeBaja(arreglo, 0, n-1);
    cout << "El maximo valor en el arreglo: " << max << endl;
    return 0;
}