//
// Created by binny on 06/10/2025.
//

#ifndef NAUTILUS_FUNCIONESPILAS_HPP
#define NAUTILUS_FUNCIONESPILAS_HPP

void construir(struct Pila & pilaTAD);
bool esPilaVacia(const struct Pila & pilaTAD);
void apilar(struct Pila & pilaTAD, const struct ElementoPila & elemento);
struct ElementoPila desapilar(struct Pila & pilaTAD);
void imprimir(const struct Pila & pilaTAD);

#endif //NAUTILUS_FUNCIONESPILAS_HPP