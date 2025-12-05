#include <iostream>
#include <climits>
using namespace std;

#define N 10

int ContarEmpresas(int empresas[][10]){
    int i=0;
    int contador =0;
    while (i<N and empresas[i][0] != -1) {
        contador++;
        i++;
    }
    return contador;
}

int max(int a, int b) {
    return  a>b ? a : b;
}

int calcularMaxProduccion(int * arreglo,int inicio, int fin) {
    if (inicio == fin) return arreglo[inicio];

    int medio = (inicio+fin)/2;
    int max_izq = calcularMaxProduccion(arreglo,inicio, medio);
    int max_der = calcularMaxProduccion(arreglo,medio+1,fin);

    return max(max_izq,max_der);
}

int contar(int* arreglo, int numBuscado, int inicio, int fin) {
    if (inicio == fin) {
        if (arreglo[inicio] == numBuscado) return 1;
        else return 0;
    }

    int medio = (inicio+fin)/2;
    int cant_izq = contar(arreglo, numBuscado, inicio, medio);
    int cant_der = contar(arreglo, numBuscado, medio+1, fin);

    return cant_izq+cant_der;
}

int ElegirMayorRepeticiones(int empresas[][10], int* arr_maxProduccion, int cantidad_empresas){

    int min_repeticion = INT_MAX;
    int indice_elegido = -1;
    for (int i=0;i<cantidad_empresas;i++) {
        int maxProduccion = arr_maxProduccion[i];
        int nRepeticionMaxProduccion = contar(empresas[0], maxProduccion, 0,10);
        if (nRepeticionMaxProduccion < min_repeticion) {
            min_repeticion = nRepeticionMaxProduccion;
            indice_elegido = i;
        }
    }

    return indice_elegido;
}

void HallarMaxProducciones(int empresas[][10], int cantidad_empresas, int* arr_cantHorasPicos) {
    for (int i=0;i<cantidad_empresas;i++) {
        arr_cantHorasPicos[i] = calcularMaxProduccion(empresas[i],0,9);
    }
}

int main() {
    //el -1 es solo un delimitador

    int empresas[N][10] = {
        {15,12,10,17,15,18,18,18,12,16},
        {14,17,17,17,17,12,14,14,12,12},
        {16,18,20,20,15,18,16,18,18,16},
        {-1}
    };

    int cantidad_empresas = ContarEmpresas(empresas);
    int arr_maxProduccion[cantidad_empresas];
    HallarMaxProducciones(empresas, cantidad_empresas, arr_maxProduccion);

    int indice_empresa_elegida = ElegirMayorRepeticiones(empresas, arr_maxProduccion, cantidad_empresas);
    cout << "La empresa elegida por Splinter es la empresa " << indice_empresa_elegida +1 << endl;

    return 0;
}