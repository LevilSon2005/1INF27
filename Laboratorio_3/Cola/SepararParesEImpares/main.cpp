#include <iostream>
#include <cmath>
#include "BibliotecaCola/funcionesCola.h"
#include "BibliotecaCola/Cola.h"
using namespace std;

void separarParesImpareConDig(struct Cola &cola) {
    int numPar = 0;
    int numImpar = 0;

    int kpar=0;
    int kimpar=0;
    while(!esColaVacia(cola)) {
        struct ElementoCola elemento = desencolar(cola);
        int num = elemento.codigo;
        cout<<"num: "<<num<<endl;
        if (num%2==0) {
            numPar += num*(int)pow(10,kpar);
            kpar++;
        }
        else {
            numImpar += num*(int)pow(10,kimpar);
            kimpar++;
        }
        cout<<"numPar: "<<numPar<<endl;
        cout<<"numImpar: "<<numImpar<<endl;


    }

    cout<<"-----------"<<endl;

    while (numPar>0) {

        int num = numPar%10;
        cout<<numPar<<" - "<<num<<endl;
        numPar /= 10;
        struct ElementoCola elemento {num};
        encolar(cola, elemento);
    }

    while (numImpar>0) {
        int num = numImpar%10;
        cout<<numImpar<<" - "<<num<<endl;

        numImpar /= 10;
        struct ElementoCola elemento {num};
        encolar(cola, elemento);
    }
}

void separarParesImparesEncoladas(struct Cola &cola) {
    if (esColaVacia(cola)) return;

    int n = cola.longitud;
    int cantPares = 0;

    // PASO 1: Contar pares
    cout << "\n=== PASO 1: Contando pares ===" << endl;
    for (int i = 0; i < n; i++) {
        struct ElementoCola e = desencolar(cola);
        if (e.codigo % 2 == 0) {
            cantPares++;
        }
        encolar(cola, e);
    }
    cout << "Total pares: " << cantPares << endl;
    cout << "Cola despues de contar: ";
    imprimir(cola);

    if (cantPares == 0 || cantPares == n) return;

    // PASO 2: Bubble sort adaptado - mover PARES hacia el inicio
    cout << "\n=== PASO 2: Separando con bubble sort ===" << endl;

    for (int i = 0; i < n - 1; i++) {
        cout << "\n--- Pasada " << (i+1) << " ---" << endl;

        for (int j = 0; j < n - 1; j++) {
            struct ElementoCola primero = desencolar(cola);
            struct ElementoCola segundo = desencolar(cola);

            // Si primero es IMPAR y segundo es PAR → intercambiar
            if (primero.codigo % 2 != 0 && segundo.codigo % 2 == 0) {
                cout << "  Intercambiando: " << primero.codigo << " (impar) con "
                     << segundo.codigo << " (par)" << endl;
                encolar(cola, segundo);  // PAR primero
                encolar(cola, primero);  // IMPAR después
            } else {
                encolar(cola, primero);
                encolar(cola, segundo);
            }
        }

        // Rotar para siguiente pasada
        encolar(cola, desencolar(cola));

        cout << "  Cola: ";
        imprimir(cola);
    }

    // Ajuste final: rotar para dejar el orden correcto
    encolar(cola, desencolar(cola));

    cout << "\n=== RESULTADO FINAL ===" << endl;
}


    // PASO 3: Rotar para que los pares queden adelante
    // Los pares están al final, rotamos n-cantPares elementos

// }

int main() {
    struct Cola cola;
    construir(cola);

    struct ElementoCola e1 = {5};
    struct ElementoCola e2 = {2};
    struct ElementoCola e3 = {8};
    struct ElementoCola e4 = {3};
    struct ElementoCola e5 = {9};
    struct ElementoCola e6 = {4};
    struct ElementoCola e7 = {1};

    encolar(cola, e1);
    encolar(cola, e2);
    encolar(cola, e3);
    encolar(cola, e4);
    encolar(cola, e5);
    encolar(cola, e6);
    encolar(cola, e7);

    imprimir(cola);
    // separarParesImpareConDig(cola);

        separarParesImparesEncoladas(cola);

    cout<<"-------"<<endl;
    return 0;
}