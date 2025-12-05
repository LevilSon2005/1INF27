//Fecha:  sábado 06 Setiembre 2025 
//Autor: Ana Roncal 

#ifndef COLA_ELEMENTOCOLA_H
#define COLA_ELEMENTOCOLA_H
#include "../BibliotecaArbolBinarioBusqueda/ArbolBinarioBusqueda.h"
struct ElementoCola {
    struct NodoArbolBinarioBusqueda* nodo;
    int codigo;
    char nombre[30];
    char especialidad[30];
    float creditos;
};
#endif //COLA_ELEMENTOCOLA_H