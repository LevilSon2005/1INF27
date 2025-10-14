#include <iostream>
#include <ostream>
using namespace std;
#include "BibliotecaPila/funcionesPila.h"
#include "BibliotecaPila/Pila.h"
#define N 7
int servidor[N][N]={
    {0,0,0,0,0,0,0},
    {10,0,20,30,0,20,40},
    {0,0,0,0,0,100,0},
    {0,0,0,0,0,80,0},
    {50,10,5,10,0,100,4},
    {100,0,0,0,0,0,0},
    {0,0,0,0,0,0,0}
};

//Retorna el indice del servidor atanque "SKYNERD"
int skynerd(struct Pila pila) {
    cout<<"Version Inicial"<<endl;
    imprimir(pila);
    while (pila.longitud>1) { //para que solo quede 1 al final
        struct ElementoPila elemento_a= desapilar(pila);
        struct ElementoPila elemento_b = desapilar(pila);
        int a = elemento_a.numero;
        int b = elemento_b.numero;
        if (servidor[a-1][b-1]!=0) {
            apilar(pila,elemento_a);
        }else {
            apilar(pila, elemento_b);
        }
        cout<<"Iteracion"<<endl;
        imprimir(pila);
    }
    int candidato = pila.inicio->elemento.numero;
    bool esSkynerd=true;
    for (int i=0;i<7;i++) {
        if (candidato-1 != i) {
            if (servidor[candidato-1][i]==0){
                esSkynerd=false;
                return 0;
            }
        }
    }
    return candidato;
}

int main() {
    struct Pila pila_indices;
    construir(pila_indices);
    struct ElementoPila elemento;
    for (int i=7;i>0;i--) {
        elemento.numero= i;
        apilar(pila_indices, elemento);
    }
    int Skynerd= skynerd(pila_indices);
    cout<<Skynerd<<endl;


    return 0;
}