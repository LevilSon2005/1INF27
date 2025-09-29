//
// Created by binny on 26/09/2025.
//

#ifndef MY_BIBLIOTECAPILAS_NODOPILA_HPP
#define MY_BIBLIOTECAPILAS_NODOPILA_HPP
#include "ElementoPila.hpp"
struct NodoPila {
    struct ElementoPila elemento;
    struct NodoPila* siguiente;
};

#endif //MY_BIBLIOTECAPILAS_NODOPILA_HPP