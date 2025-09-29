#include <iostream>
#include "My_BibiotecaPilas/funcionesPila.hpp"
#include "My_BibiotecaPilas/Pila.hpp"
using namespace std;
int main() {
    struct Pila pila1;
    construir(pila1);
    if (esPilaVacia(pila1)) cout <<"Al menos inicializo bien"<<endl;

    struct ElementoPila elemento;
    elemento.numero = 15;
    apilar(pila1, elemento);
    imprimir(pila1);

    elemento.numero = 8;
    apilar(pila1, elemento);
    imprimir(pila1);

    elemento.numero = 19;
    apilar(pila1, elemento);
    imprimir(pila1);


}