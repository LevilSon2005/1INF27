//Fecha:  sábado 06 Setiembre 2025 
//Autor: Ana Roncal 

#ifndef COLA_ELEMENTOCOLA_H
#define COLA_ELEMENTOCOLA_H
#include "../Bib_ABB/ABB.hpp"
struct ElementoCola {
    struct NodoABB* nodo;
    int codigo;
    char nombre[30];
    char especialidad[30];
    float creditos;
};
#endif //COLA_ELEMENTOCOLA_H