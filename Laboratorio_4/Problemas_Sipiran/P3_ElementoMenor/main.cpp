#include <iostream>
#include <climits>
using namespace std;

///TODO: PROBLEMA 3
///3. Un arreglo está rotado en algún punto desconocido. Encontrar el
/// elemento mínimo del arreglo. Asumir que todos los elementos son
/// distintos.
/// Ejemplo:
/// Entrada: {5, 6, 1, 2, 3, 4}
/// Salida: 1

int hallarMin(int a, int b) {
    if (a<b) return a;
    else return b;
}

int encontrarMenor(int * arreglo, int inicio, int final) {
    if (inicio == final) return arreglo[inicio];
    if (inicio > final ) return INT_MAX;


    int medio = (inicio + final)/2;
    int menor_izq = encontrarMenor(arreglo, inicio, medio-1);
    int menor_der = encontrarMenor(arreglo, medio+1, final);

    cout<<"menor_izq = "<<menor_izq<<endl;
    cout<<"menor_der = "<<menor_der<<endl;
    cout<<"actual = "<<medio<<endl;
    return hallarMin( hallarMin(menor_izq, arreglo[medio]),menor_der);
}


int main() {
    int arreglo[] = {5, 6, 2, 3, 4};
    int n=sizeof(arreglo)/sizeof(arreglo[0]);

    int menor = encontrarMenor(arreglo, 0, n-1);
    cout << menor << endl;
    return 0;
}