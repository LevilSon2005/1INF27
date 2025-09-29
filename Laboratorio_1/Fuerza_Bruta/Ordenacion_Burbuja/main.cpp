#include <iostream>
using namespace std;

int arr[7] = {89,45,68,90,29,34,27};
int n = 7;


void intercambiar(int a, int b) {
    int aux = arr[a];
    arr[a] = arr[b];
    arr[b] = aux;
}
int main() {
    for (int i=0;i<n;i++) {
        for (int k=0;k<n-i-1;k++) {
            if (arr[k]>arr[k+1] ) intercambiar(k, k+1);
        }
    }
    //Impresion para comprobar el arreglo
    for (int i=0;i<n;i++) cout<<arr[i]<<" ";
}
