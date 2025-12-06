#include <iostream>
#include <climits>
using namespace std;


//TODO: 5. Dado un arreglo de enteros el cual primero crece y luego decrece.
// Encontrar el máximo valor en el arreglo.
// Ejemplo:
// Entrada:{8, 10, 20, 80, 100, 200, 400, 500, 3, 2, 1}
// Salida: 500

int hallarMax(int* arreglo, int inicio, int fin) {
    if (inicio == fin) return arreglo[inicio];
    if (inicio > fin) return INT_MIN;

    int medio = (inicio + fin) / 2;
    if (arreglo[medio+1] > arreglo[medio]) {
        return hallarMax(arreglo, medio+1, fin);
    }else {
        return hallarMax(arreglo, inicio, medio);
    }
}

int main() {
    int arreglo[] = {8, 10, 20, 80, 100, 200, 400, 500, 3, 2, 1};
    int n= sizeof(arreglo)/sizeof(arreglo[0]);

    int max = hallarMax(arreglo, 0, n-1);
    cout<<max<<endl;
    return 0;
}