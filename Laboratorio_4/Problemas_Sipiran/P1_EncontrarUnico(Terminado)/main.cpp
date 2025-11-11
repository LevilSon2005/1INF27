#include <iostream>

///1. Dado un arreglo ordenado en el cual todos los elementos aparecen
///dos veces y un elemento aparece una sola vez. Encontrar el
/// elemento que aparece una sola vez. El algoritmo debe tener
/// complejidad O(log n).
/// Ejemplo:
///
///Entrada: {1, 1, 3, 3, 4, 5, 5, 7, 7, 8, 8}
///
///Salida: 4

using namespace std;

int encuentraElementoUnico(int* arreglo,int inicio,int fin) {
    if (inicio == fin) return arreglo[inicio];

    int medio = (inicio + fin) /2;
    //como siempre que se divide a la mitad, el indice queda par,
    //Antes de que aparezca el elemento unico: los pares, inicio de dupla
    // Despues de que aparezca el elemento unico: los pares, final de la dupla

    if (medio%2==0) {
        //estamos antes del repetido, como se que el sig tampoco es unico, empiezo en medio+2
        if (arreglo[medio] == arreglo[medio+1]) {
            return encuentraElementoUnico(arreglo,medio+2,fin);
        }
        //signfica que estoy despues del elemento unico o en el elemento unico
        //puede que sea el elemento unico o sea el fin de una dupla que está despues del elemento unico

        //si es el fin de una dupla
        else if (arreglo[medio] == arreglo[medio-1]){
            return encuentraElementoUnico(arreglo,inicio,medio);
        }

        //si no es el inicio ni fin de una dupla es el elemento unico
        else
            return arreglo[medio];
    }
    //todo: cuando son impares
    else {    //si es antes del elemento unico
        if (arreglo[medio] == arreglo[medio-1])
            return encuentraElementoUnico(arreglo,medio+1, fin);
        //cuando es igual o despues del elemento unico

        //cuando es despues: impar=inicio dupla
        else if (arreglo[medio] == arreglo[medio+1])
            return encuentraElementoUnico(arreglo,inicio, medio-1);
        else
            return arreglo[medio];
    }


}

int main() {
    int arreglo[] = {0,1,1,3,3,5,5,7,7,9,9};
    int n= sizeof(arreglo)/sizeof(arreglo[0]);

    int unico = encuentraElementoUnico(arreglo,0,n-1);
    cout<<"elemento unico: "<< unico<<endl;

    int arreglo2[] = {1, 1, 3, 3, 4, 5, 5, 7, 7, 8, 8};
    n= sizeof(arreglo2)/sizeof(arreglo2[0]);

    unico = encuentraElementoUnico(arreglo2,0,n-1);
    cout<<"elemento unico: "<< unico<<endl;

    int arreglo3[] = {1, 1, 3, 3, 5, 5, 7, 7, 8, 8, 9};
    n= sizeof(arreglo3)/sizeof(arreglo3[0]);

    unico = encuentraElementoUnico(arreglo3,0,n-1);
    cout<<"elemento unico: "<< unico<<endl;
    return 0;
}