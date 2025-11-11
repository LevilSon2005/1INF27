#include <iostream>
#include <climits>
using namespace std;

///4. Se tiene un arreglo que puede contener números positivos y
/// negativos. Encontrar la suma de números contiguos que tengan la
/// suma máxima.
/// Ejemplo:
///
/// Entrada: {-2, -5, 6, -2, -3, 1, 5, -6}
///
/// Salida: 7 (Los elementos que suman el máximo son 6, -2, -3, 1, 5)

int max(int a, int b) {
    return a > b ? a : b;
}

int hallarMaxSumaCentro(int* arreglo, int medio, int inicio, int fin) {
    int derecha = 0, izquierda = 0;
    int suma_max_izq= INT_MIN, suma_max_derecha = INT_MIN;
    for (int i=medio;i>=inicio;i--) {
        izquierda += arreglo[i];
        if (izquierda > suma_max_izq) suma_max_izq = izquierda;
    }

    for (int i=medio+1;i<=fin;i++) {
        derecha += arreglo[i];
        if (derecha > suma_max_derecha) suma_max_derecha = derecha;
    }

    return suma_max_izq + suma_max_derecha;
    // return max(max(suma_max_izq, suma_max_derecha),suma_max_izq + suma_max_derecha);
}

int hallarSumaMax(int * arreglo, int inicio, int fin) {
    if (inicio == fin ) return arreglo[inicio];
    if (inicio > fin ) return 0;

    int medio = (inicio +  fin)/2;
    int sumaMax_izq = hallarSumaMax(arreglo, inicio, medio);
    cout << "la suma maxima izquierda " << sumaMax_izq << endl;
    int sumaMax_der = hallarSumaMax(arreglo, medio+1, fin);
    cout << "la suma maxima derecha " << sumaMax_der << endl;
    int sumaMax_centro = hallarMaxSumaCentro(arreglo, medio, inicio, fin);
    cout << "la suma maxima del centro " << sumaMax_centro << endl;

    return max(max(sumaMax_izq, sumaMax_centro), sumaMax_der);
}

int main() {
    int arreglo[] = {-2, -5, 6, -2, -3, -1, 5, -6};
    int n = sizeof(arreglo) / sizeof(arreglo[0]);

    int sumMax = hallarSumaMax(arreglo, 0, n-1);
    cout << "suma maxima: " << sumMax << endl;
    return 0;
}