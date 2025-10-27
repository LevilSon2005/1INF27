#include <iostream>
#include "BibliotecaPila/funcionesPila.h"
#include "BibliotecaPila/Pila.h"
#include <ctime>
using namespace std;
#define N 8
#define m 3
int fondoIndice(Pila pila) {
    if (pila.inicio == NULL) return -1;
    NodoPila* actual = pila.inicio;
    while (actual->siguiente != NULL) {
        actual = actual->siguiente;
    }
    return actual->elemento.numero;
}

int main() {
    int arr[N]={1,3,-1,-3,5,3,6,7};
    int n = sizeof(arr)/sizeof(arr[0]);
    int ventanas_max[N]{};


    for (int i=0;i<=n-m;i++) {
        struct Pila pila;
        construir(pila);
        for (int k=i;k<i+m;k++) {
            struct ElementoPila e {arr[k]};

            //desapilar opciones que ya no sirven
            while (!esPilaVacia(pila) and arr[k] > cima(pila).numero) {
                desapilar(pila);
            }
            apilar(pila,e);
        }
        int max = fondoIndice(pila);
        cout<<max<<endl;
    }
    return 0;
}