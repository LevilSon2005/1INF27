#include <iostream>
using namespace std;
// TODO: 1. Dado un arreglo ordenado en el cual todos los elementos aparecen
//  dos veces y un elemento aparece una sola vez. Encontrar el
//  elemento que aparece una sola vez. El algoritmo debe tener
//  complejidad O(log n).
//  Ejemplo:
//  Entrada: {1, 1, 3, 3, 4, 5, 5, 7, 7, 8, 8}
//  Salida: 4

int buscaSolo(int* arreglo, int inicio, int fin) {
    if (inicio == fin) return arreglo[inicio];
    if (inicio > fin) return -1; //NO ENCONTRADO

    int medio = (inicio+fin)/2;

    //cuando es par
    if (medio%2==0) {
        //si está antes del elemento solo -> par: primero de la dupla
        if (arreglo[medio+1] == arreglo[medio]) {
            return buscaSolo(arreglo, medio+2, fin);
        }else //cuando cae en el elemento solo o despues
            return buscaSolo(arreglo, inicio, medio);
    }
    //cuando es impar
    else{
        //antes del elemento solo: impar->segundo elemento de la dupla
        if (arreglo[medio-1]==arreglo[medio]) {
            return buscaSolo(arreglo, medio+1, fin);
        }
        else //cuando cae en el elemento despues(no puede caer en el elemento solo, porque ese siempre es par)
            return buscaSolo(arreglo, inicio, medio-1);
    }


}

int main() {
    int arreglo[]= {1, 1, 3, 3, 4, 5, 5, 7, 7, 8, 8};
    int n= sizeof(arreglo)/sizeof(arreglo[0]);

    int elemento_solo = buscaSolo(arreglo, 0, n-1);
    cout<<"El elemento sin pareja es : "<<elemento_solo<<endl;;
    return 0;
}