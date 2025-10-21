#include <iostream>
using namespace std;

/// BUSCA CEROS:
///
/// Dado un arreglo de 0’s y 1’s dado que tiene todo los ceros primeros y los unos después.
///
/// Encuentra el número de ceros
//                           indice_inicio  indice_fin
int cuentaCeros(int* arr, int n, int inicio, int fin, int contador) {
    if (inicio>fin) return contador;

    int medio = (inicio+fin)/2;
    //todo: si el medio es cero -> todo lo de la derecha son ceros - me faltaria analizar la izq
    // como quiero analizar la izq, lo que cambio es el final

    //UN PASO Y DEJA LO DEMÁS AL RESTO DE LA RECURSION
    if (arr[medio] == 0) {
        //el contador se actualiza lo que se devolvio de la otra dimension más lo de la derecha (fin - medio + 1)
        contador = cuentaCeros(arr, n, inicio, medio-1, contador+fin-medio+1);
        return contador;
    }else { //todo: arr[medio] ==1  -> debo buscar zona derecha - Cambio medio por inicio
        //el contador, no se devuelve asi nomás, porque en este punto no se encontraron ceros, solo se llama a la
        //recursion para que se encarge de buscar lo demás
        contador = cuentaCeros(arr,n,medio+1,fin,contador);
        return contador;
    }
}

//TODO: DIVIDE Y VENCERÁS
int main() {
    int arr[] = {1,1,1,0,0,0,0, 0};
    int n=sizeof(arr)/sizeof(arr[0]);
    int cant_ceros = 0;
    cout<<"La cantidad de ceros es: "<<cuentaCeros(arr, n,0,n-1, cant_ceros)<<endl;
    return 0;
}