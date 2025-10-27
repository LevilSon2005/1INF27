#include <iostream>
#include <climits>
using namespace std;


/*Se tiene un arreglo que puede contener numeros positivos y negativos,
 * Nos piden hallar la suma mx consecutivas. La suma puede ser de cuantos espacios del arreglo quieres
 * siempre y cuando sea consecutivos
 *
 * Estrategia:
 * Dividir, hallar suma max de la izquierda, derecha
 * Y hallar la suma hecha desde el medio
 */

#define N 6

int DevolverMax(int a, int b) {
    if (a>b) return a;
    else return b;
}

//hallo la sumaMax por la izquier, la sumaMax por derecha y luego la suma de ambos lados
int HallarSumaDesdeMedio(int *arr,int inicio,int medio,int fin) {
    int suma=0;
    int sumaMaxIzquierda =INT_MIN, sumaMaxDerecha = INT_MIN;

    //tenemos dos suma, una que acumula la suma poco a poco, y el otro que solo guarda el max
    for (int i=medio;i>=inicio;i--) {
        suma += arr[i];
        if (suma > sumaMaxIzquierda) {
            sumaMaxIzquierda = suma;
        }
    }

    suma =0;
    for (int i=medio+1;i<=fin;i++) {
        suma += arr[i];
        if (suma>sumaMaxDerecha) {
            sumaMaxDerecha = suma;
        }
    }

    return  DevolverMax(DevolverMax(sumaMaxIzquierda, sumaMaxDerecha), sumaMaxIzquierda+sumaMaxDerecha);
}

int HallarSumaMax(int *arr,int inicio,int fin) {
    if (inicio == fin) return arr[inicio];

    int medio = (inicio+fin)/2;
    int sumaMaxDerecha = HallarSumaMax(arr, inicio,medio);
    int sumaMaxIzquierda = HallarSumaMax(arr,medio+1, fin);

    int sumaMedio = HallarSumaDesdeMedio(arr,inicio,medio,fin);

    return DevolverMax(DevolverMax(sumaMaxDerecha, sumaMaxIzquierda), sumaMedio);

}

int main() {
    int arr[N] = {-10,-1,2,3,-7,2};
    int n = sizeof(arr)/sizeof(arr[0]);
    int maxSuma = HallarSumaMax(arr,0,n-1);
    cout<<"Suma maxima: "<<maxSuma<<endl;
    return 0;
}