#include <iostream>
using namespace std;

int HallarMaxEnSubeYBaja(int* arr,int n,int inicio ,int fin) {
    if (inicio>=fin) return arr[inicio];

    //paso minimo
    int medio = (inicio+fin)/2;
    //todo: cuando el siguiente es menor que el medio - buscamos el max en izquierda
    if (medio<fin and arr[medio+1]<arr[medio]) {
         return HallarMaxEnSubeYBaja(arr,n,inicio,medio);
    }
    //todo: cuando el sig es mayor, sigue subiendo, debo seguir buscando el max en la derecha
    else  {
        return HallarMaxEnSubeYBaja(arr,n,medio+1,fin);
    }
}

int main() {
    int arr[] = {8 , 10 , 20 , 80 , 100 , 200 , 400 , 500 , 3 , 2 , 1};
    int n = sizeof(arr)/sizeof(arr[0]);
    int max = HallarMaxEnSubeYBaja(arr,n,0,n-1);
    cout<<max<<endl;
    return 0;
}
