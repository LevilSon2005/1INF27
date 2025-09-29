#include <iostream>
#include <cmath>
using namespace std;

void convertir_base(int num,int cant_elementos,int base,int *cromosoma){
    int i=cant_elementos-1;
    int residuo, cociente;
    while (num>0) {
        residuo = num%base;
        cociente = num/base;
        cromosoma[i] = residuo;
        num = cociente;
        i--;
    }
}

void imprimir_cromosoma(int* cromosoma, int cant_elementos) {
    cout<<"[ ";
    for (int i = 0; i < cant_elementos; i++) {
        cout<<cromosoma[i]<<" ";
    }
    cout<<"]"<<endl;
}


//n_elementos = 5
// base = 2 posibilidades (lo pones en la mochila o no)
int main() {
    int cant_elementos =5;
    int base=2; //porque 1 mochila : dentro de mochila(1)  o  fuera mochila(0)
    int capacidadMochila = 15;
    int pesos[5]={4,1,8,3,10};
    int precios[5]={3,5,2,8,9};
    int cromosoma[5]{};

    for (int i=0;i<=( pow(base,cant_elementos)-1);i++) {
        convertir_base(i,cant_elementos,base,cromosoma);
        cout<<i<<":";
        imprimir_cromosoma(cromosoma,cant_elementos);
    }

    return 0;
}