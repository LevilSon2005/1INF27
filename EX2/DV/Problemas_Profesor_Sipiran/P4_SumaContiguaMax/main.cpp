#include <iostream>
#include <climits>
using namespace std;

// TODO: 4. Se tiene un arreglo que puede contener números positivos y
//          negativos. Encontrar la suma de números contiguos que tengan la
//          suma máxima.
//          Ejemplo:
//          Entrada: {-2, -5, 6, -2, -3, 1, 5, -6}
//          Salida: 7 (Los elementos que suman el máximo son 6, -2, -3, 1, 5)

int max(int a, int b) {
    return a > b ? a : b;
}

int HallarSumaCentro(int* arreglo,int inicio, int fin, int medio) {
    int suma_izq =INT_MIN, suma_der=INT_MIN, derecha=0, izquierda=0;

    for (int i=medio;i>=inicio;i--) {
        derecha += arreglo[i];
        if (suma_izq < derecha) {
            suma_izq = derecha;
        }
    }

    for (int i=medio+1;i<=fin;i++) {
        izquierda += arreglo[i];
        if (suma_der < izquierda) {
            suma_der = izquierda;
        }
    }

    return  max(max(suma_izq,suma_der), suma_izq +suma_der);
}

int HallarMaxSumaContigua(int* arreglo, int inicio ,int fin) {
    if (inicio == fin ) return arreglo[inicio];

    int medio = (inicio + fin) / 2;
    int suma_izq = HallarMaxSumaContigua(arreglo, inicio, medio);
    int suma_der = HallarMaxSumaContigua(arreglo, medio+1 , fin);
    int suma_centro = HallarSumaCentro(arreglo, inicio, fin, medio);

    return max(max(suma_der,suma_izq),suma_centro);
}

int main() {
    int arreglo[] = {-2, -5, 6, -2, -3, 1, 5, -6};
    int n = sizeof(arreglo) / sizeof(arreglo[0]);

    int max_suma = HallarMaxSumaContigua(arreglo, 0,n-1);
    cout << max_suma << endl;
    return 0;
}