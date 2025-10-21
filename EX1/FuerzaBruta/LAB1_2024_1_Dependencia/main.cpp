#include <iostream>
#include <cmath>
using namespace std;


struct Guerrero {
    int codigo;
    int poder;
    int tipoArmas_para_ser_vencidos[3]{};
    int cant_armas_para_ser_vencidos =0;
};

struct Arma {
    char letra;
    int poder;
    int tipo;
    char armas_pre_requisitos[3]{};
    int cant_armas_prerequisitos=0;
};

struct Mochila {
    int poder_mochila;
    char armas_mochila[10]{};
    int cant_armas_mochilas=0;
};

void cargar_guerreros(struct Guerrero * guerreros) {
    guerreros[0].codigo =1;
    guerreros[0].poder =120;
    guerreros[0].tipoArmas_para_ser_vencidos[0]=2;
    guerreros[0].cant_armas_para_ser_vencidos =1;

    guerreros[1].codigo =2;
    guerreros[1].poder =160;
    guerreros[1].tipoArmas_para_ser_vencidos[0]=1;
    guerreros[1].tipoArmas_para_ser_vencidos[1]=3;
    guerreros[1].cant_armas_para_ser_vencidos =2;

    guerreros[2].codigo =3;
    guerreros[2].poder =80;
    guerreros[2].tipoArmas_para_ser_vencidos[0]=3;
    guerreros[2].cant_armas_para_ser_vencidos =1;
}

void cargar_armas(struct Arma* armas) {
    armas[0].letra = 'Z';
    armas[0].poder =60;
    armas[0].tipo = 3;
    armas[0].cant_armas_prerequisitos =0;

    armas[1].letra = 'P';
    armas[1].poder =80;
    armas[1].tipo = 1;
    armas[1].armas_pre_requisitos[0] ='Z';
    armas[1].cant_armas_prerequisitos =1;

    armas[2].letra = 'R';
    armas[2].poder =38;
    armas[2].tipo = 2;
    armas[2].cant_armas_prerequisitos =0;

    armas[3].letra = 'D';
    armas[3].poder =25;
    armas[3].tipo = 2;
    armas[3].armas_pre_requisitos[0] ='R';
    armas[3].cant_armas_prerequisitos =1;

    armas[4].letra = 'E';
    armas[4].poder =49;
    armas[4].tipo = 2;
    armas[4].cant_armas_prerequisitos =0;

    armas[5].letra = 'F';
    armas[5].poder =57;
    armas[5].tipo = 1;
    armas[5].cant_armas_prerequisitos =0;

    armas[6].letra = 'G';
    armas[6].poder =68;
    armas[6].tipo = 3;
    armas[6].cant_armas_prerequisitos =0;

    armas[7].letra = 'h';
    armas[7].poder =35;
    armas[7].tipo = 2;
    armas[7].armas_pre_requisitos[0] ='Z';
    armas[7].armas_pre_requisitos[1] ='E';
    armas[7].cant_armas_prerequisitos =2;

    armas[8].letra = 'D';
    armas[8].poder =62;
    armas[8].tipo = 2;
    armas[8].armas_pre_requisitos[0] ='R';
    armas[8].cant_armas_prerequisitos =1;

    armas[4].letra = 'J';
    armas[4].poder =42;
    armas[4].tipo = 2;
    armas[4].cant_armas_prerequisitos =0;

    armas[3].letra = 'K';
    armas[3].poder =36;
    armas[3].tipo = 1;
    armas[3].armas_pre_requisitos[0] ='Z';
    armas[3].cant_armas_prerequisitos =1;

    armas[4].letra = 'L';
    armas[4].poder =54;
    armas[4].tipo = 3;
    armas[4].cant_armas_prerequisitos =0;
}

///CONDICIONES DE LA MOCHILA:
///
/// - Un arma por mochila
///  - El arma debe ser el tipo que puede vencer al otro guerrero
///  - Si el arma tiene pre-requisitos, estos tbm deben ir en la misma mochila
///  - El poder de todas las armas debe ser mayor al guerrero

#define MAX_GUERREROS 3
#define MAX_ARMAS 12
#define MAX_MOCHILAS 3

void cambiarBase(int numero,int *cromosoma_actual,int cant_armas,int base) {
    //inicializo el cromosoma_actual
    for (int i=0;i<cant_armas;i++) {
        cromosoma_actual[i] =0;
    }

    int k=cant_armas-1;
    while (numero>0 and k>=0){
        int residuo =  numero%base;
        numero = numero/base;
        cromosoma_actual[k--] = residuo;
    }
}

//recuerda llenar las mochilas luego de validacion
//Requisitos: poder mayor al guerrero, armas pre requisitos, tipo guerrero = tipo arma
bool validarMultimochila(int *cromosoma_actual,struct Guerrero* guerreros, int cant_guerreros,
                         struct Arma* armas, int cant_armas, struct Mochila* mochilas, int cant_mochilas) {

    //reinicia las mochilas - para validar con cada combinacion que entra
    for (int i=1;i<= cant_mochilas;i++) {
        mochilas[i].poder_mochila =0;
        for (int k=0;k<mochilas[i].cant_armas_mochilas;k++) {
            mochilas[i].armas_mochila[k] =0;
        }
        mochilas[i].cant_armas_mochilas=0;
    }

    //recorro el cromosoma actual
    for (int i=0;i<cant_armas;i++) {

    }
}

void EncontrarMochilaParaCadaGuerrero(struct Guerrero* guerreros, int cant_guerreros,
                                    struct Arma* armas, int cant_armas,
                                    struct Mochila* mochilas, int cant_mochilas) {
    // struct Mochila mejoresMochila[MAX_MOCHILAS]{};
    bool existeSolucion = false;
    int base =  cant_armas+1;
    int cant_soluciones = (int)pow(base, cant_armas);
    int cromosoma_actual[MAX_ARMAS] = {0}; //En que mochila va cada arma
    int mejor_cromosoma[MAX_ARMAS] = {0}; //La mejor solucion

    //todo: para obtener todas las combinaciones
    for (int i=0;i<cant_soluciones;i++){
        cambiarBase(i,cromosoma_actual,cant_armas,base);

        //todo: debo verificar si mi cromosoma actual cumple la condicion de poder con los 3 guerreros
        //validar si al final, las mochilas con sus armas cumplem los requisitos:
        //Requisitos: poder mayor al guerrero, armas pre requisitos, tipo guerrero = tipo arma
        if (validarMultimochila(cromosoma_actual, guerreros, cant_guerreros,
                            armas, cant_armas, mochilas, cant_mochilas)) {
            existeSolucion = true;
            // llenarMochilas(mochila, cant_mochilas, cromosoma_actual, armas, cant_armas);
            for (int k=0;k<cant_armas;k++) {
                mejor_cromosoma[k] = cromosoma_actual[k];
            }
        }
    }

    //para mostrar
    if (!existeSolucion) cout<<"Po no se convertira en un guerrero Dragon :("<<endl;
    else {
        for (int i=1;i<=cant_mochilas;i++) {
            cout<<"Guerrero "<<i<<endl;
            cout<<"Poder: "<<mochilas[i].poder_mochila<<endl;
            cout<<"Armas en mochila para vencerlo: ";
            for (int k=0;k<mochilas[i].cant_armas_mochilas;k++) {
                cout<<mochilas[i].armas_mochila[k]<<" ";
            }
            cout<<endl;
        }
    }
}

int main() {
    int cant_guerreros =3;
    struct Guerrero guerreros[MAX_GUERREROS]{};
    cargar_guerreros(guerreros);

    int cant_armas =12;
    struct Arma armas[MAX_ARMAS]{};
    cargar_armas(armas);

    int cant_mochilas =3;
    struct Mochila mochilas[MAX_MOCHILAS]{};

    EncontrarMochilaParaCadaGuerrero(guerreros, cant_guerreros, armas, cant_armas,
                                    mochilas, cant_mochilas);

    return 0;
}