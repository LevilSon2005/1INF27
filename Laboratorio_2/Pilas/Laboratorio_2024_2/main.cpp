#include "BibliotecaPila/funcionesPila.h"
#include "BibliotecaPila/Pila.h"
#include <iostream>
#include <iomanip>
using namespace std;

#define N 3
struct Efectivo efectivos[N]= {
    {1,2,4},
    {2,2,1},
    {3,2,4}
};

void imprimir_numero_individual(int n_efectivos) {
    cout<<"Las agrupaciones serian: ";
    for (int i = 0; i < n_efectivos; i++) {
        if (i!=0)cout<<",";
        cout<<"{"<<i+1<<"}";
    }
    cout<<endl;
}

int comparacion_rangos(struct Efectivo a,struct Efectivo b) {
    if (a.grado > b.grado) return 1;
    else if (a.grado < b.grado) return -1;
    else {//si son iguales en grado - se evalua el tiempo
        if (a.tiempo > b.tiempo) return 1;
        else if (a.tiempo < b.tiempo) return -1;
        else return 0;
    }
}

int HallarAgrupaciones(int n_efectivos) {
    int totalAgrupaciones = n_efectivos;
    struct Pila pila;
    construir(pila);

    for (int i = 0; i < n_efectivos; i++) {
        // Limpiar la pila antes de usar
        // while (!esPilaVacia(pila)) {
        //     desapilar(pila);
        // }
        //
        // struct ElementoPila lider;
        // lider.efectivo = efectivos[i];
        // apilar(pila, lider);

        int k = i + 1;
        while (k < n_efectivos and
               comparacion_rangos(efectivos[i], efectivos[k]) > 0) {
            // struct ElementoPila elemento;
            // elemento.efectivo = efectivos[k];
            // apilar(pila, elemento);
            totalAgrupaciones++;
            k++;
        }
    }
    return totalAgrupaciones;
}

int main() {
    struct Pila pila;
    construir(pila);

    //APILAMOS LA PILA AL REVES
    int n_efectivos=3;
    for (int i=n_efectivos;i>0;i--) {
        struct ElementoPila elemento;
        elemento.efectivo=efectivos[i];
        apilar(pila, elemento);
    }
    //SIEMPRE SE IMPRIMEN GRUPOS INDIVIDUALES
    imprimir_numero_individual(n_efectivos);
    //IMPRIMIR GRUPOS DE 2 O MAS
    int cant_soluciones=HallarAgrupaciones(n_efectivos);
    cout<<"Cantidad soluciones: "<<cant_soluciones<<endl;

    return 0;
}