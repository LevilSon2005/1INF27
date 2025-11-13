#include <iostream>
using namespace std;
void Merge(int A[], int inicial, int medio, int final) {
    int longitud1, longitud2;
    int i, p, q;

    longitud1 = medio - inicial + 1; //4
    longitud2 = final - medio;//4

    int P[longitud1+1];
    int Q[longitud2+1];

    P[longitud1]=INT_MAX;//valor "infinito"
    Q[longitud2]=INT_MAX;//valor "infinito"

    //Copiamos los subarreglos
    for (i=inicial; i<=medio; i++) P[i-inicial]=A[i];
    for (i=medio+1; i<=final; i++) Q[i-(medio+1)]=A[i];

    p=q=0;//índices para manejar los subarreglos auxiliares
    //Realizamos la mezcla
    for (i=inicial;i<=final; i++)
        if (P[p]<Q[q])//tomamos el menor de los menores de cada subarreglo
            A[i]=P[p++];
        else
            A[i]=Q[q++];

    cout<<"Parcial: ";
    for(int i=0;i<=final;i++)
        cout<<A[i]<<" ";
    cout<<endl;
}

void MergeSort(int A[], int inicial, int final) {
    //CASO BASE
    if (inicial >= final) {//POR REVISAR OJO!!!!!!!
        return;
    }
    //PARTE RECURSIVA
    int medio = (inicial + final) / 2;
    MergeSort(A, inicial, medio);//Afecta a la primera mitad del arreglo, trayéndolo ordenado
    MergeSort(A, medio+1, final);//Afecta a la segunda mitad del arreglo, trayéndolo ordenado
    Merge(A, inicial, medio, final);//Combinamos las 2 mitades para que el arreglo esté ordenado
}

int main() {
    int A[]={11,4,7,1,6,3,2,9};
    int n=8;

    cout<<"Original: ";
    for(int i=0;i<n;i++)
        cout<<A[i]<<" ";
    cout<<endl;

    MergeSort(A,0,n-1);

    cout<<"Ordenado: ";
    for(int i=0;i<n;i++)
        cout<<A[i]<<" ";
    cout<<endl;

    return 0;
}
