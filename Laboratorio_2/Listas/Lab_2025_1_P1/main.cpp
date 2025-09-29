#include "BibliotecaLista/funcionesLista.h"
#include <iostream>
#include <cstring>
#include <iomanip>

#include "BibliotecaLista/Lista.h"
using namespace std;

char* asignar_cadena(const char* buffer) {
    char* cadena;
    cadena =  new char[strlen(buffer)+1]{};
    strcpy(cadena, buffer);
    return cadena;
}

void imprimir_cuadrigas(struct Lista listaTAD) {
    struct NodoLista* recorrido = listaTAD.inicio;
    while (recorrido) {
        cout<<"[ ID: "<<recorrido->elemento.id<<", ";
        cout<<"Nombre: "<<recorrido->elemento.nombre<<", ";
        cout<<"Equipo: "<<recorrido->elemento.equipo<<" ]"<<endl;
        recorrido = recorrido->siguiente;
    }
}

void cargar_lista(struct Lista &lista) {
    struct ElementoLista elemento;

    elemento.id = 17;
    elemento.nombre = asignar_cadena("Messala");
    elemento.equipo = asignar_cadena("Rojo");
    insertarAlFinal(lista, elemento);

    elemento.id = 4;
    elemento.nombre = asignar_cadena("Ben-Hur");
    elemento.equipo = asignar_cadena("Azul");
    insertarAlFinal(lista, elemento);

    elemento.id = 12;
    elemento.nombre = asignar_cadena("Artax");
    elemento.equipo = asignar_cadena("Verde");
    insertarAlFinal(lista, elemento);

    elemento.id = 7;
    elemento.nombre = asignar_cadena("Drusus");
    elemento.equipo = asignar_cadena("Negro");
    insertarAlFinal(lista, elemento);

    elemento.id = 8;
    elemento.nombre = asignar_cadena("Drusus");
    elemento.equipo = asignar_cadena("Amarillo");
    insertarAlFinal(lista, elemento);

    elemento.id = 6;
    elemento.nombre = asignar_cadena("Drusus");
    elemento.equipo = asignar_cadena("Amarillo");
    insertarAlFinal(lista, elemento);

}

bool esNodoPar(struct NodoLista* nodo) {
    return (nodo->elemento.id % 2==0);
}

void ordenar_lista(struct Lista &listaTAD) {
    int n_par=0, n_impar=0;
    struct NodoLista* par_inicio = nullptr;
    struct NodoLista* par_final;
    struct NodoLista* impar_inicio=nullptr;
    struct NodoLista* impar_final;
    struct NodoLista* recorrido_2;
    struct NodoLista* recorrido = listaTAD.inicio;

    //HADO DOS SUBLISTAS
    while (recorrido) {
        recorrido_2 = recorrido;
        //Es importante primero avanzar, para que las modificaciones
        //no afecten el recorrido
        recorrido = recorrido->siguiente;
        if (esNodoPar(recorrido_2)) {
            if (n_par==0) {
                par_inicio = recorrido_2;
                par_final = recorrido_2;
                n_par++;
            }else{
                par_final->siguiente = recorrido_2;
                par_final = recorrido_2;
                par_final->siguiente = nullptr;
                n_par++;
            }
        }

        if (not esNodoPar(recorrido_2)) {
            if (n_impar==0) {
                impar_inicio = recorrido_2;
                impar_final = recorrido_2;
                n_impar++;
            }
            else {
                impar_final->siguiente = recorrido_2;
                impar_final = recorrido_2;
                impar_final->siguiente = nullptr;
                n_impar++;
            }
        }

    }
    //SI ES QUE EN LA LISTA NO HABIA PARES
    if (par_inicio== nullptr) listaTAD.inicio = impar_inicio;
    else listaTAD.inicio = par_inicio; //si es que si habia pares


    /*Si es que no hay impares, está solo inicializar la lista con
     * los pares, ya no se le agrega la sublista de impares
     */
    //si es que si hay impares
    if (impar_inicio != nullptr) {
        par_final->siguiente = impar_inicio;
    }
}

int main() {

    struct Lista lista;
    construir(lista);

    cargar_lista(lista);
    imprimir_cuadrigas(lista);

    ordenar_lista(lista);
    cout<<"---------------------------"<<endl;
    imprimir_cuadrigas(lista);

    return 0;
}