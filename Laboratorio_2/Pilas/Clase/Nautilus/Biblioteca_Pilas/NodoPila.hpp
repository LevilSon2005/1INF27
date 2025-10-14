//
// Created by binny on 06/10/2025.
//

#ifndef NAUTILUS_NODOPILA_HPP
#define NAUTILUS_NODOPILA_HPP
#include "ElementoPila.hpp"
struct NodoPila {
    struct ElementoPila elemento; /*Dato que cambia por double, char, struct */
    struct NodoPila * siguiente; /*puntero a una variable de tipo struct Nodo*/
};
#endif //NAUTILUS_NODOPILA_HPP