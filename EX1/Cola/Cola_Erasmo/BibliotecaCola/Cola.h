//Fecha:  sábado 06 Setiembre 2025 
//Autor: Ana Roncal 

#ifndef COLA_COLA_H
#define COLA_COLA_H
#include "NodoCola.h"
struct Cola {
    struct NodoCola * inicio;
    struct NodoCola * last1;
    struct NodoCola * fin;
    int longitud1;
    int longitud2;
    int longitud;
};
#endif //COLA_COLA_H