#include <iostream>
using namespace std;


/*    Nos piden el Max de  incrementos consecutivos
 *    DEBE SER O(n) = nlog(n)
 *
 */

int HallarMax(int a, int b) {
    if (a<b) return b;
    return a;
}

int HallarIncrementosDesdeElMedio(int* arr,int inicio,int medio,int fin) {
    //se inicia en 1 porque
    int incrementoIzq =1, incrementoDer =1;

    if (arr[medio+1]<arr[medio]) return 1;
    for (int i=medio;i>inicio;i--) {
        if (arr[i]>arr[i-1]) incrementoIzq++;
        else break; //es importante que apenas aparezca uno menor, rompa el bucle
    }

    //como estamos evaluando el siguiente(  +1) no debe tocar el fin
    for (int i=medio+1;i<fin;i++) {
        if (arr[i+1]>arr[i]) incrementoDer++;
        else break;
    }

    return incrementoIzq + incrementoDer;

}

int HallarLaCantidadIncrementosConsecutivos(int* arr,int inicio,int fin) {
    if(inicio == fin) return 1;

    int medio = (inicio+fin)/2;
    int incrementosIzq = HallarLaCantidadIncrementosConsecutivos(arr,inicio,medio);
    int incrementosDer = HallarLaCantidadIncrementosConsecutivos(arr, medio+1,fin);

    int incrementosMed = HallarIncrementosDesdeElMedio(arr,inicio,medio,fin);

    return HallarMax(HallarMax(incrementosIzq,incrementosDer),incrementosMed);
}

int main() {
    int arr[]={8,19,1,2,13,11};
    int n=sizeof(arr)/sizeof(arr[0]);

    int maxConsecutivos = HallarLaCantidadIncrementosConsecutivos(arr,0,n-1);
    cout<<maxConsecutivos<<endl;
    return 0;
}