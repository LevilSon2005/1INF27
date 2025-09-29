#include <iostream>
using namespace std;

#define M 5
#define N 5

int almacen[N][M] = {
    {4,3,6,8,7},
    {6,3,8,4,10},
    {2,15,1,2,13},
    {5,1,10,11,2},
    {10,4,7,9,4}
};

int almacen_reponer[N][M]{};

//halla el mayor en horizontaly vertical y luego compara y me da el mayor de ambos
int HallarMayor(int x,int y,int n,int m){
    //cuando pasamos de una fila a la siguiente, cuando volvamos devolverá suma de esa fial
    //por eso cuando lleguemos a una fila que ya no existe devuelve cero
    if (x==n) return 0; //terminé filas
    //señal para pasar a otra fila, se le suma cero porque en ese indice ya es inaccesible, uno mas del limite
    if (y==m) return HallarMayor(x+1,0,n,m);
    return almacen[x][y]>HallarMayor(x,y+1,n,m)?(almacen[x][y]):(HallarMayor(x,y+1,n,m));
}

void completar_stock(int x,int y,int n,int m){
    int mayor = HallarMayor(x,y,n,m);
    cout<<"mayor: "<<mayor<<endl;

}

int main() {
    int n=5, m=5;
    int x=0,y=0; //posicion inicial: la esquina de la matriz

    completar_stock(x,y,n,m);
    return 0;
}