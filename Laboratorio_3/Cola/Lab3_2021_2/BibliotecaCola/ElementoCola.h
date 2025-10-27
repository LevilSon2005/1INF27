//Fecha:  sábado 06 Setiembre 2025 
//Autor: Ana Roncal 

#ifndef COLA_ELEMENTOCOLA_H
#define COLA_ELEMENTOCOLA_H
struct ElementoCola {
    int piso;
    int movimiento =0; // 1: SUBIDA - 0: BAJADA
    char nombre[30];
    char especialidad[30];
    float creditos;
};
#endif //COLA_ELEMENTOCOLA_H