//
// Created by binny on 09/10/2025.
//

#ifndef PASAPILA_FUNCIONESPILAS_HPP
#define PASAPILA_FUNCIONESPILAS_HPP
#include <iostream>
#include <iomanip>
#include "Pila.hpp"
using namespace std;
/*
* void construir(struct Pila & pilaTAD);
bool esPilaVacia(const struct Pila & pilaTAD);
int longitud(const struct Pila & pilaTAD) ;
struct ElementoPila cima(const struct Pila & pila) ;
void apilar(struct Pila & pilaTAD, const struct ElementoPila & elemento);
struct ElementoPila desapilar(struct Pila & pilaTAD);
void imprimir(const struct Pila & pilaTAD);
void destruir(struct Pila & pilaTAD);
struct NodoPila cima(struct Pila piltaTAD);
 */

void construir(struct Pila& pila);

bool esPilaVacia(const struct Pila& pila);

int longitud(const struct Pila& pila) ;

//cima devuelve un struct Elemento
struct ElementoPila cima(const struct Pila& pila);

void apilar(class Pila& pila, const struct ElementoPila& elemento);

void imprimir(const struct Pila& pila);

#endif //PASAPILA_FUNCIONESPILAS_HPP