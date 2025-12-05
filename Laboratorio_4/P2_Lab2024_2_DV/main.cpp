#include <iostream>
#include <climits>
using namespace std;
#define N 10
 int max(int a, int b) {
     return a >= b ? a : b;
 }

int HallarMaxSubeBaja(int* arreglo, int inicio,int fin) {
    if (inicio == fin) return arreglo[inicio];

    int medio = (inicio + fin)/2;
    int max_izq = HallarMaxSubeBaja(arreglo, inicio, medio);
    int max_der = HallarMaxSubeBaja(arreglo, medio+1, fin);

    return max(max_izq, max_der);
}

int HallarMaxPureza(int muestras[][N],int cantidad_muestras) {
    int maxTotal =INT_MIN;
    for (int i=0;i<cantidad_muestras;i++) {
        int maxArreglo = HallarMaxSubeBaja(muestras[i], 0,9);
        if (maxArreglo > maxTotal) maxTotal = maxArreglo;
    }
    return maxTotal;
}

int contarCeros(int* arreglo,int inicio,int fin) {
     if (inicio == fin) {
         if (arreglo[inicio] == 0) return 1;
         else return 0;
     }
     int medio = (inicio + fin)/2;
     int cant_izq = contarCeros(arreglo,inicio,medio);
     int cant_der = contarCeros(arreglo,medio+1,fin);
     return cant_izq+cant_der;
 }

void HallarNivelesConMayorCantNiveles(int muestras[][N], int cantidad_muestras) {
     int cantNiveles[cantidad_muestras];
     int maxNiveles = INT_MIN; //el nivel con menor cantidad de estratos ceros
     for (int i=0;i<cantidad_muestras;i++) {
        cantNiveles[i] = 10 - contarCeros(muestras[i],0,9);
         // cout <<cantNiveles[i]<<endl;
         if (cantNiveles[i] > maxNiveles) maxNiveles = cantNiveles[i];
     }

     cout << "Las muestras con mayor cantidad de nivele son: ";
     int k=0;
     for (int i=0;i<cantidad_muestras;i++) {
         if (cantNiveles[i] == maxNiveles) {
             if (k==0) {
                 cout << i+1;
                 k++;
             }
             else {
                 cout<< ","<<i+1;
                 k++;
             }
         }
     }
     cout << " con "<< maxNiveles << " estratos" <<endl;
 }

int main() {
    int muestras[N][N] = {
        {0,0,0,3,3,7,5,5,1,1},
        {8,8,10,9,9,5,4,4,2,0},
        {3,5,8,9,7,6,4,2,0,0},
        {9,7,7,4,4,4,2,0,0,0},
        {0,2,2,3,3,4,4,5,3,3},
        {0,0,0,0,0,0,2,3,4,5},
        {1,2,2,3,3,4,3,2,0,0},
        {0,0,0,0,0,0,3,5,5,7},
        {6,5,5,2,2,1,0,0,0,0},
        {3,2,2,0,0,0,0,0,0,0}
    };
    int cantidad_muestras = sizeof(muestras) / sizeof(muestras[0]);
    int maxPureza = HallarMaxPureza(muestras,cantidad_muestras);
    cout << "MaxPureza = " << maxPureza << endl;

    HallarNivelesConMayorCantNiveles(muestras,cantidad_muestras);
    return 0;
}