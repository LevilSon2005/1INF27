#include <iostream>
using namespace std;
#define M 6
#define N 6

/*Devuelve la cantidad de unidades encontradas <> Devuelve la suma en su rastreo
 * Incluido en la suma la pos inicial
 */
int rastreo(int x,int y,int n,int m, int radio, int mapa[][M]) {
    //caso base - condicion de parada
    // if (radio_expansion==0) return mapa[x][y];
    int suma=0;

    if (x+radio>=n or x-radio<0 or y+radio>=m or y-radio<0) return suma;

    //SUMAMOS HORIZONTALES Y VERTICALES
    //Si el radio es cero, no quiero el valor se sume dos veces dento del for (x-radio = x+radio)
    if (radio ==0) suma += mapa[x][y];
    else {//ahora si sumamos los anillos
        for (int i=y-radio;i<=y+radio;i++) suma+= mapa[x-radio][i] + mapa[x+radio][i];
        for (int i=x-radio+1;i<x+radio;i++) suma+= mapa[i][y-radio] + mapa[i][y+radio];
    }
    //recursion
    suma += rastreo(x,y,n,m,radio+1,mapa);
    return suma;
}


int main() {
    int mapa[N][M] = {
        {0,0,0,1,0,1},
        {0,0,1,0,0,0},
        {0,1,0,0,0,1},
        {1,0,0,0,0,0},
        {0,1,0,0,1,0},
        {0,0,0,0,1,0}
    };

    int x=4, y=4; //posicion inicial
    int n=6, m=6;
    int radio_expansion =0;

    int unidades_contadas = rastreo(x,y,n,m,radio_expansion, mapa);

    cout<<"Las unidades contadas son: "<<unidades_contadas<<endl;
    return 0;
}