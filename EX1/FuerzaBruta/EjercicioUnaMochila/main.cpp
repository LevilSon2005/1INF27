#include <iostream>
#include <cmath>
using namespace std;

//Nota: Para este problema se pide escoger la mejor mochila, con mayor precio
//      pero que cumpla la restricción del peso. PESO_MAXIMO=50;


/*
    Tu tarea:

    Generar TODAS las combinaciones posibles de paquetes
    Evaluar cada combinación (descartar las que excedan 20 kg)
    Encontrar la combinación que maximice el valor total
    Mostrar qué paquetes llevar y el valor total obtenido

 */

/// GLOBALES

struct Objeto {
    char paquete;
    int peso;
    int valor;
};

struct Mochila {
    int peso_maximo; //restricción
    int peso_actual;
    int valor_actual; //optimización
};

const int MAX_OBJETOS = 10;

/// SOLUCION:

void copiarCromosoma(const int* cromosoma_actual, int* mejor_cromosoma, int cantObjetos) {
    for (int k=0;k<cantObjetos;k++) {
        mejor_cromosoma[k] = cromosoma_actual[k];
    }
}

void cambiarBase(int numero,int *cromosoma_actual,int cantObjetos, int base) {

    //inicializamos el cromosoma_actual
    for (int i=0;i<cantObjetos;i++) {
        cromosoma_actual[i]=0;
    }

    //el primer residuo se va al ultimo indice = cant -1
    int k=cantObjetos-1;

    while (numero>0 and k>=0) {
        int residuo = numero%base;
        int cociente = numero/base;
        numero = cociente;
        cromosoma_actual[k] = residuo;
        k--;
    }
}

//todo: evalua que el peso no supere el peso maximo, si cumple devuelve el valor_actual del cromosoma, sino devuelve cero
int evaluarCromosoma(int* cromosoma_actual, struct Objeto* objetos,int cantObjetos,struct Mochila &mochila) {

    mochila.peso_actual=0;
    mochila.valor_actual = 0;

    //evaluamos el peso de ese cromoma
    for (int i=0;i<cantObjetos;i++) {
        if (cromosoma_actual[i]==1) { //el objeto va en la mochila
            mochila.peso_actual += objetos[i].peso;
            mochila.valor_actual += objetos[i].valor;
        }
    }
    //validamos si cumple la restriccion del peso
    if (mochila.peso_actual > mochila.peso_maximo) return 0; //no cumple
    else return mochila.valor_actual; //si cumple y se devuelve la suma del peso de la cromosoma actual

}

void mostrarMejorCromosoma(int* mejor_cromosoma,struct Objeto* objetos, int cantObjetos, int mejor_valor) {
    cout<<"El mayor valor es : "<<mejor_valor<<endl;

    int numObjeto = 0; //para validar si cuando imprime lleva coma
    cout<<"{";
    for (int i=0;i<cantObjetos;i++) {
        if (mejor_cromosoma[i] == 1) {
            if (!numObjeto) cout<<objetos[i].paquete;
            else cout<<","<<objetos[i].paquete;
            numObjeto++;
        }
    }
    cout<<"}";
}

void HallarMejorSolucion(struct Objeto* objetos,int cantObjetos,struct Mochila &mochila) {
    int cromosoma_actual[MAX_OBJETOS]{};
    int mejor_cromosoma[MAX_OBJETOS]{};
    int mejor_valor =0;
    int base=2;
    int cantidad_soluciones = (int)pow(base,cantObjetos);

    //todo: cada solución lo convertimos en un cromosoma
    for (int i=0;i<cantidad_soluciones;i++) {
        cambiarBase(i,cromosoma_actual,cantObjetos,base);
        /// Evalua que el peso no supere el peso maximo, si cumple devuelve el valor_actual del cromosoma, sino devuelve cero
        int valor_actual = evaluarCromosoma(cromosoma_actual,objetos,cantObjetos,mochila);

        //todo: actualizamos el mejor_cromosoma
        if (valor_actual > mejor_valor) {
            mejor_valor = valor_actual;
            copiarCromosoma(cromosoma_actual, mejor_cromosoma, cantObjetos);
        }
    }

    mostrarMejorCromosoma(mejor_cromosoma,objetos,cantObjetos, mejor_valor);
}




int main() {
    //todo: creamos los objetos que van dentro de la mochila
    struct Objeto objetos[MAX_OBJETOS]={
        {'A',5,40},
        {'B',10,70},
        {'C',15,90},
        {'D',8,60}
    };
    int cantObjetos = 4;

    //todo: creamos nuestra mochila
    struct Mochila mochila={20,0,0};

    //todo: queremos hallar la mejor solucion
    HallarMejorSolucion(objetos,cantObjetos,mochila);

    return 0;
}