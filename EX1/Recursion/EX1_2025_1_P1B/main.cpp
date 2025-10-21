#include <iostream>
using namespace std;
#define N 9
#define M 9

enum direcciones {HORIZONTAL, VERTICAL, DIAGONAL_IZQ, DIAGONAL_DER};
enum movimientos {ARRIBA, DERECHA, ABAJO, IZQUIERDA,
                  DIAG_IZQ_ARR, DIAG_DER_ARR, DIAG_DER_ABAJO, DIAG_IZQ_ABAJO};
//todo: guarda la cantidad de la letra que me piden buscar en las 4 direcciones
int cantRepeticionLetra[4] = {0}; // cada direccion tiene una cantidad de repeticion de la letra
int movimientos[8][2] = {
    {-1,0}, //ARRIBA
    {0,1},  //DERECHA
    {1,0},  //ABAJO
    {0,-1},  //IZQUIERDA
    {-1,-1}, //DIAG_IZQ_ARR
    {-1,1}, //DIAG_DER_ARR
    {1,1},  //DIAG_DER_ABAJO
    {1,-1}  //DIAG_IZQ_ABAJO
};
void imprimir_almacen(char matriz[][M]) {
    for (int i = 0; i < M; i++) {
        for (int k = 0; k< N; k++) {
            cout<<matriz[i][k]<<"  ";
        }
        cout<<endl;
    }
}

int cantEnSemiDireccion(char matriz[][M], int posx,int posy,char letra, int dx,int dy){
    int seEncuentra=0;
    //si se sale fuera de la matriz
    if (posx<0 or posx>=N or posy<0 or posy>=N) return 0;

    //que hago ahora hmm
    if (matriz[posx+dx][posy+dy] == letra) {
        seEncuentra++;
    }
    return seEncuentra + cantEnSemiDireccion(matriz,posx+dx,posy+dy,letra,dx,dy);
}

int cantUnaDireccion(char matriz[][M],int posx, int posy, char letra,int mov1[], int mov2[]) {

    //paso en posicion actual
    int cantSemiDireccion1 =  cantEnSemiDireccion(matriz, posx,posy,letra, mov1[0],mov1[1]);
    int cantSemiDireccion2 =  cantEnSemiDireccion(matriz, posx,posy,letra, mov2[0],mov2[1]);

    cout<<"cant1: "<<cantSemiDireccion1<< " - "<<" cant2: "<<cantSemiDireccion2;
    cout<<" -> CantTotal : "<<cantSemiDireccion1 + cantSemiDireccion2<<endl;
    return cantSemiDireccion1 + cantSemiDireccion2;
}

int BuscarMayorRepeticion(char matriz[][M],int posx,int posy,char letra) {
    //sale de los limites
    cantRepeticionLetra[HORIZONTAL] = cantUnaDireccion(matriz,posx,posy,letra,movimientos[IZQUIERDA], movimientos[DERECHA]);
    cantRepeticionLetra[VERTICAL] = cantUnaDireccion(matriz,posx,posy, letra,movimientos[ARRIBA], movimientos[ABAJO]);
    cantRepeticionLetra[DIAGONAL_IZQ] = cantUnaDireccion(matriz,posx,posy,letra, movimientos[DIAG_IZQ_ARR], movimientos[DIAG_DER_ABAJO]);
    cantRepeticionLetra[DIAGONAL_DER] = cantUnaDireccion(matriz,posx,posy,letra,movimientos[DIAG_DER_ARR], movimientos[DIAG_IZQ_ABAJO]);

    int mayor = 0;
    int mayorIndice =0;
    for(int i=0;i<4;i++){
        if (cantRepeticionLetra[i]>mayor) {
            mayor = cantRepeticionLetra[i];
            mayorIndice = i;
        }
    }
    return mayorIndice;
}

void cargarMovs(int ind_repeticion, int mov1[], int mov2[]) {
    if (ind_repeticion == HORIZONTAL) {
        for (int i=0;i<2;i++) mov1[i] = movimientos[DERECHA][i] ;
        for (int i=0;i<2;++i) mov2[i] = movimientos[IZQUIERDA][i] ;
    }
    if (ind_repeticion == VERTICAL) {
        for (int i=0;i<2;i++) mov1[i] = movimientos[ARRIBA][i] ;
        for (int i=0;i<2;++i) mov2[i] = movimientos[ABAJO][i] ;
    }
    if (ind_repeticion == DIAGONAL_IZQ) {
        for (int i=0;i<2;i++) mov1[i] = movimientos[DIAG_IZQ_ARR][i] ;
        for (int i=0;i<2;++i) mov2[i] = movimientos[DIAG_DER_ABAJO][i];
    }
    if (ind_repeticion == DIAGONAL_DER) {
        for (int i=0;i<2;i++) mov1[i] = movimientos[DIAG_DER_ARR][i] ;
        for (int i=0;i<2;++i) mov2[i] = movimientos[DIAG_IZQ_ABAJO][i];
    }
}

//elimina la letra de la posicion actual mas el mov en la matriz
void EliminarLetraSubDireccion(char matriz[][M],int posx,int posy,char letra, int mov[]) {
    int dx=mov[0];
    int dy=mov[1];

    if (posx<0 or posx>=N or posy<0  or posy>=M) return;

    //PASO: (El minimo paso que debe cumplir la recursion) --> elimina la letra si es que coincide
    if (matriz[posx+dx][posy+dy]==letra) matriz[posx+dx][posy+dy]='.';
    //El que hace el resto:
    EliminarLetraSubDireccion(matriz,posx+dx, posy+dy,letra,mov);

}

void EliminarLetraEnDireccion(char matriz[][M],int posx,int posy,char letra, int mov1[], int mov2[]) {

    EliminarLetraSubDireccion(matriz, posx,posy,letra,mov1);
    EliminarLetraSubDireccion(matriz, posx,posy,letra,mov2);
}

int main(){
    char matriz[N][M] = {
        {'.','.','.','.','.','.','.','.','.'},
        {'.','A','.','.','.','B','.','.','.'},
        {'.','.','V','A','.','.','.','.','.'},
        {'.','B','.','D','.','V','B','A','.'},
        {'.','.','B','B','.','.','.','.','.'},
        {'.','A','.','B','.','.','.','.','.'},
        {'.','.','.','.','.','B','A','.','.'},
        {'.','.','.','V','.','.','.','.','.'},
        {'.','.','.','B','.','.','.','.','A'},
    };
    cout<<"Mapa incial: "<<endl;
    imprimir_almacen(matriz);

    //todo: devuelve el indice del arreglo de direcciones con mayor repeticiones
    int posx= 3, posy=3;
    int ind_repeticion = BuscarMayorRepeticion(matriz,posx,posy,'B');
    cout<<"Indice Cant Mayor: "<<ind_repeticion<<endl;

    //todo: elimina todas la letra en la direccion con mayor repeticion
    int mov1[2]={0};
    int mov2[2]={0};
    cargarMovs(ind_repeticion, mov1, mov2);
    EliminarLetraEnDireccion(matriz,posx,posy,'B',mov1, mov2);
    cout<<"Almacen despues:"<<endl;
    imprimir_almacen(matriz);
    return 0;
}