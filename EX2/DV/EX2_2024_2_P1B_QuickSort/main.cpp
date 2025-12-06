#include <iostream>
#include <cstring>
#include <string>
using namespace std;


struct Plato {
    string nombre;
    int cantidadDisponible;
    int cantidadReservada;
    double pocentajeReservas;
};


// FUNCIÓN QUICKSORT: Ordena el arreglo usando divide y vencerás
void quickSort(int* arreglo, int inicio, int fin) {
    if (inicio >= fin )return;

    int pivote = arreglo[fin];
    //todo: i representa el ultimo elemento menor al pivote
    int i = inicio - 1; //se inicializa asi porque aun no hay elemento menor al pivote}

    for (int k=inicio;k<=fin-1;k++) {
        if (arreglo[k] > pivote) {
            i++;
            swap(arreglo[i], arreglo[k]);
        }
    }

    swap(arreglo[fin], arreglo[i+1]);

    int indice_pivote = i+1;

    quickSort(arreglo, inicio, indice_pivote-1);
    quickSort(arreglo, indice_pivote+1, fin);
}

void ordenarPlatoPorPorcentajes(struct Plato* arreglo, int inicio, int fin) {
    if (inicio >= fin)return;

    int pivote = arreglo[fin].pocentajeReservas;
    int i=inicio-1;

    for (int k=inicio;k<=fin-1;k++) {
        if (arreglo[k].pocentajeReservas < pivote) {
            i++;
            swap(arreglo[i], arreglo[k]);
        }
    }

    swap(arreglo[fin], arreglo[i+1]);

    int indice_pivote = i+1;
    ordenarPlatoPorPorcentajes(arreglo, inicio, indice_pivote-1);
    ordenarPlatoPorPorcentajes(arreglo, indice_pivote+1, fin);
}

void imprimirArregloPlatos(struct Plato* arreglo) {
    cout<<"Top 3 platos con mayor porcentaje de reservas:"<<endl;
    for (int i=0;i<3;i++) {
        cout<<arreglo[i].nombre<<" - "<<arreglo[i].pocentajeReservas<<"%"<<endl;
    }
}

void calcularPorcentajes(struct Plato* arreglo, int cant_platos) {
    for (int i=0;i<cant_platos;i++) {
        arreglo[i].pocentajeReservas =
            (arreglo[i].cantidadReservada*100.00)/arreglo[i].cantidadDisponible;
    }
}

int main() {
    struct Plato arreglo[]={
        {"Lomo Saltado", 50,30},
        {"Ceviche", 40,35},
        {"Ají de Gallina,", 30,10},
        {"Causa Limeña", 20,20},
        {"Arroz con Pollo", 60,45},
    };

    int n=sizeof(arreglo)/sizeof(arreglo[0]);

    calcularPorcentajes(arreglo, n);
    ordenarPlatoPorPorcentajes(arreglo, 0, n-1);
    imprimirArregloPlatos(arreglo);
    return 0;
}