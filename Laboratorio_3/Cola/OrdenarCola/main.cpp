#include <iostream>
using namespace std;
#include "BibliotecaCola/Cola.h"
#include "BibliotecaCola/funcionesCola.h"
int Longitud (Cola cola) {
    return cola.longitud;
}
void OrdenaCola(Cola &cola, int n) {
    //caso base
    if (esColaVacia(cola)) return;

    //para una cola de n elementos
    //todo: debo desencolar el mayor antes de mandarlo a la recursiva, ese mayor se queda pendiente para cuando
    // vuelva (baje de nivel y se encolen los mayores) - volviendolo una cola ordenada de menor a mayor

    struct ElementoCola aux, mayor;
     n = cola.longitud;
    mayor = desencolar(cola);
    int i=1;
    //recorremos n-1 porque ya sacamos uno(el mayor inicial)
    while (i<=n-1) {
        aux = desencolar(cola);
        //se queda el mayor y el menor lo encolo.
        if (mayor.codigo < aux.codigo) {
            encolar(cola, mayor);
            mayor = aux;
        }else {//aux < mayor - encolamos el menor
            encolar(cola, aux);
        }
        i++;
    }
    OrdenaCola(cola, n-1);
    //todo: los mayor que deje en cada universo se encolan desde el caso base hasta el nivel más superficial . Se vuelve menor -> mayor
    encolar(cola, mayor);
}

int main() {
    Cola cola;
    ElementoCola elemento;
    construir(cola);
    elemento.codigo=8;
    encolar (cola, elemento);
    elemento.codigo=21;
    encolar (cola, elemento);
    elemento.codigo=10;
    encolar (cola, elemento);
    elemento.codigo=15;
    encolar (cola, elemento);
    elemento.codigo=7;
    encolar (cola, elemento);
    imprimir(cola);
    OrdenaCola(cola, Longitud(cola));
    cout<<"Cola Ordenada: ";
    imprimir(cola);
    return 0;
}