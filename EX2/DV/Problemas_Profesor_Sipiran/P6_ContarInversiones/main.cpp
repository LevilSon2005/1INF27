#include <iostream>
#include <climits>
using namespace std;

// Todo: Dado un arreglo de enteros, encontrar el número de inversiones.
//  Una inversión es un par de elementos A[i] y A[j] tal que i < j y
//  A[i] > A[j].

void Merge(int* arreglo, int inicio, int medio, int fin) {

    //PASAMOS A LA MITAD IZQUIERDA DEL ARREGLO A UN ARREGLO TEMPORAL
    int cant1 = (medio-inicio) + 1;
    int temp1[cant1+1];
    temp1[cant1] = INT_MAX;
    for (int i=0;i<=cant1;i++) {
        temp1[i] = arreglo[i+inicio];
    }

    //PASAMOS A LA MITAD DERECHA A UN ARREGLO TEMPORAL
    int cant2= fin-(medio+1) +1;
    int temp2[cant2+1];
    temp2[cant2] = INT_MAX;

    for (int i=0;i<cant2;i++) {
        temp2[i] = arreglo[i+(medio+1)];
    }

    int p=0,q=0;
    for (int i=inicio; i<fin; i++) {
        if (temp1[p] < temp2[q]) {
            arreglo[i] = temp1[p];
            p++;
        }else {//temp2[q] < temp1[p]
            arreglo[i] = temp2[q];
            q++;
        }
    }

}

void MergeSort(int* arreglo, int inicio, int fin) {
    if (inicio >= fin ) return;

    int medio = (inicio + fin)/2;

    //dividen hasta lelgar al ultimo nivel: individual
    MergeSort(arreglo, inicio, medio);
    MergeSort(arreglo, medio+1, fin);
    Merge(arreglo, inicio, medio, fin);
}

int main() {
    int arreglo[] = {15,12,3,8,4,5,2};
    int n=sizeof(arreglo)/sizeof(arreglo[0]);

    // int cant_inversiones = contarInversiones(arreglo, 0, n-1);
    MergeSort(arreglo, 0, n-1);
    for (int i=0;i<n;i++) {
        cout << arreglo[i] << " ";
    }
    return 0;
}
