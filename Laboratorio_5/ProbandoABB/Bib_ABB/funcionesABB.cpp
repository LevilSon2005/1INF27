//
// Created by binny on 24/11/2025.
//

#include "funcionesABB.hpp"

void construir(struct ABB &arbol) {
    arbol.raiz = nullptr;
}

bool esArbolVacio(struct ABB arbol) {
    return arbol.raiz == nullptr;
}

bool esNodoVacio(struct NodoABB* nodo) {
    return nodo == nullptr;
}

void plantarNodoABB(struct NodoABB* &raiz, struct NodoABB* derecha, struct NodoABB* izquierda, struct ElementoABB elemento){
    struct NodoABB* nuevo = new NodoABB();
    nuevo->elemento = elemento;
    nuevo->derecha = derecha;
    nuevo->izquierda = izquierda;
    raiz = nuevo;
}

void plantarABB(struct ABB &arbol, struct ABB arbol_izq, struct ABB arbol_der, struct ElementoABB elemento) {
    plantarNodoABB(arbol.raiz, nullptr,nullptr, elemento);
}

void insertar(struct ABB &arbol, struct ElementoABB elemento) {
    insertarRecursivo(arbol.raiz, elemento);
}

void insertarRecursivo(struct NodoABB *&nodo, struct ElementoABB new_elemento) {
    if (esNodoVacio(nodo)) {
        plantarNodoABB(nodo, nullptr, nullptr, new_elemento);
    }
    else {
        if (new_elemento.numero < nodo->elemento.numero) {
            insertarRecursivo(nodo->izquierda, new_elemento);
        }else {
            insertarRecursivo(nodo->derecha, new_elemento);
        }
    }
}

//todo: imprimir por amplitud de izquierda a derecha (ITERATIVO)
void imprimir_amplitud_ID_Iterativo(const struct ABB &arbol) {
    //encolamos la raiz
    struct Cola cola;
    construir(cola);
    struct ElementoCola c_elemento {arbol.raiz}; //se guarda el el nodo, para luego tener acceso a las hijas
    encolar(cola, c_elemento);

    while (!esColaVacia(cola)) {
        c_elemento = desencolar(cola);
        cout<<c_elemento.nodo->elemento.numero<<" ";

        if (!esNodoVacio(c_elemento.nodo->izquierda)) {
            struct ElementoCola c_izq {c_elemento.nodo->izquierda};
            encolar(cola, c_izq);
        }

        if (!esNodoVacio(c_elemento.nodo->derecha)) {
            struct ElementoCola c_der {c_elemento.nodo->derecha};
            encolar(cola, c_der);
        }
    }
}

void imprimir_amplitud_ID_Iterativo_enter(const struct ABB &arbol) {
    //encolamos la raiz
    struct Cola cola;
    construir(cola);
    struct ElementoCola c_elemento {arbol.raiz}; //se guarda el el nodo, para luego tener acceso a las hijas
    encolar(cola, c_elemento);

    while (!esColaVacia(cola)) {
        int nodos_en_este_nivel = longitud(cola); // CLAVE: capturas el tamaño AHORA

        // Procesas EXACTAMENTE los nodos de este nivel
        for (int i = 0; i < nodos_en_este_nivel; i++) {
            c_elemento = desencolar(cola);
            cout<<c_elemento.nodo->elemento.numero<<" ";

            if (!esNodoVacio(c_elemento.nodo->izquierda)) {
                struct ElementoCola c_izq {c_elemento.nodo->izquierda};
                encolar(cola, c_izq);
            }

            if (!esNodoVacio(c_elemento.nodo->derecha)) {
                struct ElementoCola c_der {c_elemento.nodo->derecha};
                encolar(cola, c_der);
            }
        }
        cout<<endl;
    }
}

void imprimir_amplitud_enter(const struct ABB &arbol) {
    struct Cola cola;
    construir(cola);
    struct ElementoCola c_elemento {arbol.raiz};
    encolar(cola, c_elemento);

    while (!esColaVacia(cola)) {
        //todo: antes de encolar los hijos, medimos la longitud
        int cant_nodos = longitud(cola);

        //todo: los padres se van desencolando(el # de veces de nodos de ese nivel) y los hijos se van encolando
        for (int i=0;i<cant_nodos;i++) {
            c_elemento = desencolar(cola);
            cout<<c_elemento.nodo->elemento.numero<<" ";
            if (!esNodoVacio(c_elemento.nodo->izquierda)) {
                struct ElementoCola c_iz {c_elemento.nodo->izquierda};
                encolar(cola, c_iz);
            }
            if (!esNodoVacio(c_elemento.nodo->derecha)) {
                struct ElementoCola c_der {c_elemento.nodo->derecha};
                encolar(cola, c_der);
            }
        }
    }
}

void imprimir_amplitud_reves(const struct ABB &arbol) {
    struct Cola cola;
    construir(cola);
    struct ElementoCola c_elemento {arbol.raiz};
    encolar(cola, c_elemento);

    struct Pila pila;
    construir(pila);
    struct ElementoPila p_elemento;

    while (!esColaVacia(cola)) {
        c_elemento = desencolar(cola);

        p_elemento.numero = c_elemento.nodo->elemento.numero;
        apilar(pila, p_elemento);

        if (!esNodoVacio(c_elemento.nodo->izquierda)) {
            struct ElementoCola c_izq {c_elemento.nodo->izquierda};
            encolar(cola, c_izq);
        }
        if (!esNodoVacio(c_elemento.nodo->derecha)) {
            struct ElementoCola c_der {c_elemento.nodo->derecha};
            encolar(cola, c_der);
        }
    }

    //imprimir la pila
    imprimir(pila);
}

void pre_orden_rec(struct NodoABB* nodo) {
    if (!esNodoVacio(nodo)) {
        cout<<nodo->elemento.numero<<" ";
        pre_orden_rec(nodo->izquierda);
        pre_orden_rec(nodo->derecha);
    }
}

void imprimir_pre_orden_iterativo(const struct ABB &arbol) {//RID
    pre_orden_rec(arbol.raiz);
}



