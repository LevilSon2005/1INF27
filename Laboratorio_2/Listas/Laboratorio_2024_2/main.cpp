#include "BibliotecaLista/funcionesLista.h"
#include "BibliotecaLista/Lista.h"
using namespace std;
#include <iostream>
#include <fstream>
#include <cstring>

void apertura_lectura(ifstream &input, const char* name) {
    input.open(name, ios::in);
    if (not input.is_open()) {
        cout<<"Error en apertura_lectura: "<<name<<endl;
        exit(1);
    }else {
        cout<<"El archivo "<<name<<" se abrio"<<endl;
    }

}

char* leer_cadena(ifstream &input, char del) {
    char* cadena, buffer[30]{};
    input.getline(buffer, 30, del);
    cadena = new char[strlen(buffer)+1];
    strcpy(cadena, buffer);
    return cadena;
}

char* asignar_cadena(const char* buffer) {
    char* cadena;
    cadena = new char[strlen(buffer)+1];
    strcpy(cadena, buffer);
    return cadena;
}

int leer_int(ifstream &input) {
    int dato;
    input >> dato;
    input.get();
    return dato;
}

double leer_double(ifstream &input) {
    double dato;
    input >> dato;
    input.get();
    return dato;
}


char leer_char(ifstream &input) {
    char dato;
    input >> dato;
    input.get();
    return dato;
}


void cargar_lista(struct Lista &lista) {
    ifstream input;
    apertura_lectura(input, "Data/Data.csv");
    char* id, complejidad;
    int disponibilidad, horaPunta, velocidad=45;
    double distancia;
    struct ElementoLista elemento;
    while (true) {
        id = leer_cadena(input, ',');
        if (input.eof()) break;
        complejidad = leer_char(input);
        disponibilidad = leer_int(input);
        distancia = leer_double(input);
        horaPunta = leer_int(input);

        elemento.id = asignar_cadena(id);
        if (complejidad == 'b') elemento.tiempoPreparacion = 10;
        else if (complejidad =='m') elemento.tiempoPreparacion = 20;
        else elemento.tiempoPreparacion = 30;
        if (disponibilidad == 0) elemento.tiempoPreparacion += 5;
        elemento.tiempoEstimadoViaje = (distancia/velocidad)*60;
        if (horaPunta==1) elemento.tiempoEstimadoViaje += 10;
        insertarAlFinal(lista, elemento);
        cout<<id<<": "<<elemento.tiempoPreparacion<<"-"<<elemento.tiempoEstimadoViaje<<endl;
    }
}

//CORREGIR EL NULLPTR DEL FINAL PARA QUE NO TERMINE Y CORREGIR LAS SUMAS
void ordenar_unidades(struct Lista &listaTAD) {
    struct NodoLista* recorrido = listaTAD.inicio;
    struct NodoLista* recorrido_2;
    struct NodoLista* recorrido_aux = nullptr;
    struct NodoLista* inicio_aux = nullptr;
    struct NodoLista* anterior_aux = nullptr;
    int n_pedidos =0, unidad, unidad_aux;
    while (recorrido) {
        recorrido_2 = recorrido;
        unidad = (recorrido_2->elemento.tiempoPreparacion + recorrido_2->elemento.tiempoEstimadoViaje)%10;
        recorrido = recorrido_2->siguiente;
        if (n_pedidos==0) {
            inicio_aux = recorrido_2;
            inicio_aux->siguiente = nullptr;
            n_pedidos++;
        }else {
            recorrido_aux = inicio_aux;
            while (recorrido_aux) {
                unidad_aux = (recorrido_aux->elemento.tiempoEstimadoViaje + recorrido_aux->elemento.tiempoPreparacion)%10;
                if (unidad < unidad_aux) break;
                anterior_aux = recorrido_aux;
                recorrido_aux = recorrido_aux->siguiente;
            }
            recorrido_2->siguiente = recorrido_aux;
            if (anterior_aux != nullptr)anterior_aux->siguiente = recorrido_2;
            else inicio_aux = recorrido_2;
            n_pedidos++;
        }
    }
    listaTAD.inicio = inicio_aux;
}

void ordenar_decenas(struct Lista &listaTAD) {
    struct NodoLista* recorrido = listaTAD.inicio;
    struct NodoLista* recorrido_2;
    struct NodoLista* recorrido_aux = nullptr;
    struct NodoLista* inicio_aux = nullptr;
    struct NodoLista* anterior_aux = nullptr;
    int n_pedidos =0, decena, decena_aux;
    while (recorrido) {
        recorrido_2 = recorrido;
        decena = (recorrido_2->elemento.tiempoPreparacion + recorrido_2->elemento.tiempoEstimadoViaje)/10;
        recorrido = recorrido_2->siguiente;
        if (n_pedidos==0) {
            inicio_aux = recorrido_2;
            inicio_aux->siguiente = nullptr;
            n_pedidos++;
        }else {
            recorrido_aux = inicio_aux;
            while (recorrido_aux) {
                decena_aux = (recorrido_aux->elemento.tiempoEstimadoViaje + recorrido_aux->elemento.tiempoPreparacion)/10;
                if (decena < decena_aux) break;
                anterior_aux = recorrido_aux;
                recorrido_aux = recorrido_aux->siguiente;
            }
            recorrido_2->siguiente = recorrido_aux;
            if (anterior_aux != nullptr)anterior_aux->siguiente = recorrido_2;
            else inicio_aux = recorrido_2;
            n_pedidos++;
        }
    }
    listaTAD.inicio = inicio_aux;
}

int main() {
    struct Lista lista;
    construir(lista);
    cargar_lista(lista);
    imprimir(lista);
    ordenar_unidades(lista);
    imprimir(lista);
    ordenar_decenas(lista);
    imprimir(lista);
    return 0;
}