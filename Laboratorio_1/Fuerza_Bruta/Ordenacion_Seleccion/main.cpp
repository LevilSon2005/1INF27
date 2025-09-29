#include <iostream>
using namespace std;

/*ORDENAMIENTO POR SELECCION*/
int arr[7] ={89,45,68,90,29,34,17};
int n=7;

void intercambiar(int i, int min) {
    int aux = arr[i];
    arr[i] = arr[min];
    arr[min]=aux;
}

int main() {
    int min;
    for(int i=0;i<n;i++) { //para avanzar  en el arreglo
       //indice min
        min = i; //el primero que luego se va a comparar
        for (int k=i+1;k<n;k++) {//para encontrar el min desde indice i hasta el final
            if (arr[k]<arr[min]) min=k;//ya encontré el menor de cada subgrupo
        }
       intercambiar(i, min);//intercambio la posicion de tal manera que el i y los indic anteriores ya están ordenados
    }

    //solo es para la impresion
    for (int i=0;i<n;i++) cout<<arr[i]<<"-";
    return 0;
}
