//
// Created by binny on 09/10/2025.
//

#ifndef PASAPILA_NODOPILA_HPP
#define PASAPILA_NODOPILA_HPP
#include "ElementoPila.hpp"

struct NodoPila {
    struct ElementoPila elemento;
    NodoPila* siguiente;
};
#endif //PASAPILA_NODOPILA_HPP