//
// Created by binny on 03/12/2025.
//

#ifndef LAB5_2023_2_SKYNERD_FUNCIONESSKYNERD_HPP
#define LAB5_2023_2_SKYNERD_FUNCIONESSKYNERD_HPP

#include <iostream>
#include <iomanip>
using namespace std;

#include "BibliotecaArbolBinarioBusqueda/ArbolBinarioBusqueda.h"
#include "BibliotecaArbolBinarioBusqueda/funcionesArbolBinarioBusqueda.h"
#include "BibliotecaPila/Pila.h"
#include "BibliotecaPila/funcionesPila.h"
#include "BibliotecaCola/Cola.h"
#include "BibliotecaCola/funcionesCola.h"

int contar_niveles_recursivo(struct NodoArbolBinarioBusqueda* nodo);
int cant_Niveles(const struct ArbolBinarioBusqueda &arbol);
void imprimir_nivel_enter(const struct ArbolBinarioBusqueda &arbol);
struct NodoArbolBinarioBusqueda* encontrar_skynerd_recursivo(struct NodoArbolBinarioBusqueda* nodo) ;
struct NodoArbolBinarioBusqueda* encontrarSkynerd(const struct ArbolBinarioBusqueda &arbol);
struct NodoArbolBinarioBusqueda* encontrarSkynerdIterativo(const struct ArbolBinarioBusqueda &arbol);
void eliminar_subArbol(const struct ArbolBinarioBusqueda &arbol,struct NodoArbolBinarioBusqueda *raiz);
void recorridoInOrdenIterativo(const struct ArbolBinarioBusqueda &arbol);
void recorridoPostOrdenIterativo(const struct ArbolBinarioBusqueda &arbol);
#endif //LAB5_2023_2_SKYNERD_FUNCIONESSKYNERD_HPP