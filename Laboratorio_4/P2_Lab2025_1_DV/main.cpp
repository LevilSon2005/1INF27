#include <iostream>
#include <iomanip>
using namespace std;

enum clasificacion {ACEPTADO, RECHAZADO};
#define N 8
#define M 6
#define P 0.7

int HallarProductoCorrectos(char* arreglo, int inicio, int fin) {
    if (inicio == fin) {
        if (arreglo[inicio] == 'C') return 1;
        else return 0;
    }

    int medio = (inicio + fin) / 2;
    int cantidad_izq = HallarProductoCorrectos(arreglo, inicio, medio);
    int cantidad_der = HallarProductoCorrectos(arreglo, medio + 1, fin);

    return cantidad_izq + cantidad_der;
}

int CalcularLongitudArreglo(char* arreglo) {
    int longitud=0;
    int i=0;
    while (i<N and arreglo[i] != '\0') {
        longitud++;
        i++;
    }
    return longitud;
}

void ProcesarClasificacionLotes(char lotes[][N]) {

    for (int i=0; i<M; i++) {

        int n_productos =  CalcularLongitudArreglo(lotes[i]);
        int cant_correctos = HallarProductoCorrectos(lotes[i], 0, n_productos-1);

        double porcentaje = (double)cant_correctos/n_productos;
        // cout<< porcentaje << endl;
        int clasificacion_lote = -1; //para ver si es que algo sale mal, solo para mi debugeo
        clasificacion_lote = ((porcentaje>=P)?(ACEPTADO):(RECHAZADO));

        cout<< setw(5) << i+1 << setw(20);
        cout<< ((clasificacion_lote == ACEPTADO) ? "Aprobado" : "Rechazado") <<endl;
    }
}

int main() {

    char lotes[M][N] = {
        {'F','F','F','C','C','F','\0'},
        {'C','F','C','C','C','F','C','F'},
        {'F','C','C','C','C','C','C','C'},
        {'C','C','C','C','C','F','C','\0'},
        {'C','F','F','F','F','C','\0'},
        {'C','C','F','C','F','C','C','\0'}
    };

    cout<< setw(5) << "Lote" << setw(20) << "Estado" << endl;
    ProcesarClasificacionLotes(lotes);

    return 0;
}