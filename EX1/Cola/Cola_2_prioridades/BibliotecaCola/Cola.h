//Fecha:  sábado 06 Setiembre 2025 
//Autor: Ana Roncal 

#ifndef COLA_COLA_H
#define COLA_COLA_H
#include "NodoCola.h"
struct Cola {
    struct NodoCola * inicio;
    struct NodoCola* last1;
    struct NodoCola * fin;

    int longitud; //esto lo dejo solo para no cmabiar la biblioteca de funciones

    //las otras longitudes se cambiaran en modulos en el main
    int longitud_1;
    int longitud_2;
};
#endif //COLA_COLA_H