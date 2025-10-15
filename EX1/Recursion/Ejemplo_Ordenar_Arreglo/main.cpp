#include <iostream>
#include <climits>
using namespace std;

#define N 10
int arr[10] = {34,20,25,12,9,18,4,7,27,31};


int EncontrarIndiceMinimo( int indice, int final) {
    if (indice >= final) return indice-1; //devulevo el ultimo indice valido
    // cout<<"Aca sigue entrando a la recursividad hasta que sea igual al final"<<endl;
    int ultimo_indice = EncontrarIndiceMinimo(indice+1,final);
    // cout << "ultimo_valor = " << ultimo_valor <<" / "<<" arr[indice]: "<<arr[indice]<<" / Indice: "<<indice<<endl;
    if (arr[indice]<arr[ultimo_indice]) return indice;
    else return ultimo_indice;
}

int HallarMinArreglo(int inicio, int final) {
    int indice = inicio, minIndice=0;
    // cout<<"Imprime el indice mayor, porque esta volviendo como yoyo"<<endl;
    minIndice = EncontrarIndiceMinimo(indice, final);
    return minIndice;
}

void ordenarArreglo(int inicio, int final) {
    if (inicio>=final) return;
    int indice_min=HallarMinArreglo(inicio,final);
    cout<<"Min: "<<arr[indice_min]<<endl;
    int temporal_inicio = arr[inicio];
    arr[inicio] = arr[indice_min];
    arr[indice_min] = temporal_inicio;

    //aca va recursiva
    ordenarArreglo(inicio+1,final);
}

int main() {
    int inicio=0, final=N;
    cout<<HallarMinArreglo(inicio,final)<<endl;
    ordenarArreglo(inicio, final);

    //imprimir arreglo
    cout<<"{";
    for (int i=0;i<N;i++) {
        if (i!= N-1 )cout<<arr[i]<<" - ";
        else cout<<arr[i];
    }
    cout<<"}"<<endl;

    return 0;
}