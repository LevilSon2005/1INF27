#include <iostream>
#include <cmath>
using namespace std;

///PROBLEMA:
///
///=== PROBLEMA MULTI-MOCHILA ===
///
///Numero de paquetes: 5
///
///Numero de camiones: 3
///
///Base utilizada: 4 (0=no enviar, 1-3=camiones)
///
///Total de soluciones posibles: 1024
///
///Capacidad por camion: 25 kg
///
///Evaluando todas las soluciones...
///
///=== MEJOR DISTRIBUCION ENCONTRADA ===
///
///Prioridad total del sistema: 330 puntos
///
///Camion 1:
///  Paquetes: {A,E}
///Peso: 14 / 25 kg
///Prioridad: 90 puntos
///
///Camion 2:
///Paquetes: {B,C}
///Peso: 22 / 25 kg
///Prioridad: 140 puntos
///
///Camion 3:
///Paquetes: {D}
///Peso: 15 / 25 kg
///Prioridad: 100 puntos

struct Objeto {
    char nombre;
    int peso;
    int prioridad;
};

struct Mochila {
    int peso_maximo;
    int peso_actual;
    int prioridad_actual;
};

#define MAX_OBJETOS 20
#define MAX_MOCHILAS 20

// SOLUCION:

void cambiarBase(int numero, int* cromosoma_actual,int cantObjetos, int base) {
    //inicializo el cromosoma_actual;
    for (int i = 0; i < cantObjetos; i++) {
        cromosoma_actual[i] = 0;
    }

    int k= cantObjetos-1;
    while (numero>0 and k>=0) {
        int residuo = numero%base;
        numero = numero/base;
        cromosoma_actual[k] = residuo;
        k--;
    }
}

//validar si ninguna mochila incumple el peso_maximo, si es asi devuelve la PRIORIDAD_ACTUAL (suma prioridad), sino cero
int validarCromosomaEnMultimochila(int *cromosoma_actual,struct Objeto* objetos,int cantObjetos,struct Mochila* mochilas,int cantMochilas) {
    int sumaPrioridades=0;

    for (int i=1;i<=cantMochilas;i++){
        mochilas[i].peso_actual = 0;
        mochilas[i].prioridad_actual = 0;
    }

    for (int i=0;i<cantObjetos;i++) { //recorro cada opcion del cromosoma
        int indice_mochilaDestino = cromosoma_actual[i];
        if (indice_mochilaDestino >= 1 and indice_mochilaDestino<=cantMochilas) {
            mochilas[indice_mochilaDestino].peso_actual += objetos[i].peso;
            mochilas[indice_mochilaDestino].prioridad_actual += objetos[i].prioridad;
        }
    }

    //verifico que ninguna mochila=camion sobrepase el peso_maximo
    for (int i=1;i<=cantMochilas;i++) {
        if (mochilas[i].peso_actual > mochilas[i].peso_maximo) return 0; //incumple
        else sumaPrioridades += mochilas[i].prioridad_actual; //suma las prioridades de c/mochila <> prioridad_sistema
    }

    return sumaPrioridades;
}

void copiar_cromosoma(int *mejor_cromosoma,int* cromosoma_actual, int cantObjetos) {

    for (int i=0;i<cantObjetos;i++) {
        mejor_cromosoma[i] = cromosoma_actual[i];
        cout<<mejor_cromosoma[i]<<" ";
    }

    cout<<"----------------"<<endl;
}

/*void mostrarMejorSolucion(int* mejor_cromosoma,struct Objeto* objetos,int cantObjetos,
                          struct Mochila* mochilas,int cantMochilas, int mejor_prioridad_sistema) {
    cout<<"---------MEJOR SOLUCION ENCONTADA-----------"<<endl;
    cout<<"Prioridad total del sistema : "<<mejor_prioridad_sistema<<" puntos."<<endl;
    for (int i=0;i<cantObjetos;i++) {
        int indice_mochilaDestino = mejor_cromosoma[i];
        cout<<"Camion : "<<indice_mochilaDestino<<" , ";
        cout<<"Paquete: {"<<objetos[i].nombre<<"} ";
        cout<<"Peso: "<<objetos[i].peso<<"/"<<mochilas[indice_mochilaDestino].peso_maximo<<" ";
        cout<<"Priorida: "<<objetos[i].prioridad<<" puntos."<<endl;
    }
}*/

void mostrarMejorSolucion(int* mejor_cromosoma, struct Objeto* objetos, int cantObjetos,
                          struct Mochila* mochilas, int cantMochilas, int mejor_prioridad_sistema) {
    cout << "=== MEJOR DISTRIBUCION ENCONTRADA ===\n\n";
    cout << "Prioridad total del sistema: " << mejor_prioridad_sistema << " puntos\n\n";

    // Reiniciamos los datos de las mochilas para recalcular
    for (int i = 1; i <= cantMochilas; i++) {
        mochilas[i].peso_actual = 0;
        mochilas[i].prioridad_actual = 0;
    }

    // Mostrar por cada camion
    for (int i = 1; i <= cantMochilas; i++) {
        cout << "Camion " << i << ":\n  Paquetes: {";
        bool primero = true;
        for (int j = 0; j < cantObjetos; j++) {
            if (mejor_cromosoma[j] == i) {
                if (!primero) cout << ",";
                cout << objetos[j].nombre;
                primero = false;
                mochilas[i].peso_actual += objetos[j].peso;
                mochilas[i].prioridad_actual += objetos[j].prioridad;
            }
        }
        cout << "}\n";
        cout << "  Peso: " << mochilas[i].peso_actual << " / " << mochilas[i].peso_maximo << " kg\n";
        cout << "  Prioridad: " << mochilas[i].prioridad_actual << " puntos\n\n";
    }
}

void HallarMejorSolucionMulti(struct Objeto* objetos,int cantObjetos,struct Mochila* mochilas, int cantMochilas) {
    int cromosoma_actual[MAX_OBJETOS]{};
    int mejor_cromosoma[MAX_OBJETOS]{};
    int mejor_prioridad=0;
    int base=cantMochilas+1;
    int cant_soluciones = (int)pow(base,cantObjetos);

    //todo: cada solucion se convierte en un cromosoma
    for (int i=0;i<cant_soluciones;i++) {
        cambiarBase(i,cromosoma_actual,cantObjetos, base); //llenamos el cromosoma actual
        //validar si ninguna mochila incumple el peso_maximo, si es asi devuelve la prioridad, sino cero
        int prioridad_cromosoma =validarCromosomaEnMultimochila(cromosoma_actual,objetos,cantObjetos,mochilas,cantMochilas);

        if (prioridad_cromosoma>mejor_prioridad) {
            mejor_prioridad=prioridad_cromosoma;
            copiar_cromosoma(mejor_cromosoma, cromosoma_actual, cantObjetos);
        }
    }
    mostrarMejorSolucion(mejor_cromosoma,objetos,cantObjetos,mochilas,cantMochilas, mejor_prioridad);
}


int main() {

    //todo: creamos los objetos
    int cantObjetos =5;
    struct Objeto objetos[MAX_OBJETOS]= {
        {'A',8,50},
        {'B',12,80},
        {'C',10,60},
        {'D',15,100},
        {'E',6,40}
    };

    //todo: creamos las mochilas
    int cantMochilas = 3;
    struct Mochila mochilas[MAX_MOCHILAS]{};
    for (int i=1;i<=cantMochilas;i++) {
        mochilas[i].peso_maximo = 25;
        mochilas[i].peso_actual = 0;
        mochilas[i].prioridad_actual = 0;
    }

    HallarMejorSolucionMulti(objetos,cantObjetos,mochilas, cantMochilas);
    return 0;
}