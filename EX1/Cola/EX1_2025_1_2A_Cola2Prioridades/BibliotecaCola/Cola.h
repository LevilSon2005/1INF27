//Fecha:  sábado 06 Setiembre 2025 
//Autor: Ana Roncal 

#ifndef COLA_COLA_H
#define COLA_COLA_H
#include "NodoCola.h"
struct Cola {
    struct NodoCola * inicio;
    struct NodoCola * last1;
    struct NodoCola * inicio_aislados;
    struct NodoCola * fin;
    int longitud1;
    int longitud2;
    int longitud; //este solo se deja para evitar cambiar mucho las funciones de cola
};
#endif //COLA_COLA_H