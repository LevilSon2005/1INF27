//
// Created by binny on 06/12/2025.
//

#include "funciones.hpp"

int max(int a, int b) {
    return a > b ? a : b;
}

int altura(Nodo *nodo) {
    if (nodo == nullptr) return 0;
    return nodo->altura;
}

int factor_balance(Nodo *nodo) {
    if (nodo == nullptr) return 0;
    return altura(nodo->izq) - altura(nodo->der);
}

Nodo* rotacionDerecha(Nodo *y) {
    Nodo *x = y->izq;
    Nodo *T2 = x->der;

    // Realizar rotación
    x->der = y;
    y->izq = T2;

    // Actualizar alturas
    y->altura = 1 + max(altura(y->izq), altura(y->der));
    x->altura = 1 + max(altura(x->izq), altura(x->der));

    return x;  // Nueva raíz
}

// Rotación simple a la IZQUIERDA (caso RR)
Nodo* rotacionIzquierda(Nodo *x) {
    Nodo *y = x->der;
    Nodo *T2 = y->izq;

    // Realizar rotación
    y->izq = x;
    x->der = T2;

    // Actualizar alturas
    x->altura = 1 + max(altura(x->izq), altura(x->der));
    y->altura = 1 + max(altura(y->izq), altura(y->der));

    return y;  // Nueva raíz
}

struct Nodo* insertarAVL(struct Nodo* &nodo, int clave) {
    //INSERCCION NORMAL
    if (nodo == nullptr) {
        nodo =  new Nodo();
        nodo->dni = clave;
        nodo->izq = nullptr;
        nodo->der = nullptr;
        nodo->altura = 1;
        return nodo;
    }

    if (clave < nodo->dni) {
        nodo->izq  = insertarAVL(nodo->izq, clave);
    }
    else if (clave > nodo->dni) {
        nodo->der = insertarAVL(nodo->der, clave);
    }else {
        return nodo; //dni duplicado no insertamos
    }

    //ACTUALIZAMOS ALTURA
    nodo->altura  = 1 + max(altura(nodo->izq), altura(nodo->der));

    int balance = factor_balance(nodo);

    //ROTACIONES  4 CASOS


    // TODO: balance > 1 → Desbalanceado a la izquierda (el lado izquierdo es más alto)
    //  balance < -1 → Desbalanceado a la derecha (el lado derecho es más alto
    //  clave < nodo->izq->dni: La nueva clave se insertó en el subárbol izquierdo del hijo izquierdo
    //  clave > nodo->der->dni: La nueva clave se insertó en el subárbol derecho del hijo derecho

    if (balance >1 and clave < nodo->dni) {
        return rotacionDerecha(nodo);
    }

    if (balance <-1 and clave > nodo->dni) {
        return rotacionIzquierda(nodo);
    }

    if (balance > 1 and clave > nodo->dni) {
        nodo->izq = rotacionIzquierda(nodo->izq);
        return rotacionDerecha(nodo);
    }

    //desvalance en la drecha, pero se inserta en la izquierda
    if (balance <-1 and clave < nodo->dni) {
        nodo->der = rotacionDerecha(nodo->der);
        return rotacionIzquierda(nodo);
    }

    return nodo;
}

struct Nodo* nodoMinimo(struct Nodo* nodo) {
    while (nodo->izq != nullptr) {
        nodo = nodo->izq;
    }
    return nodo;
}

struct Nodo* eliminarNodoAVL(struct Nodo* &nodo, int clave) {
    if (nodo == nullptr) return nullptr;

    //busqueda
    if (clave <nodo->dni) {
        nodo->izq = eliminarNodoAVL(nodo->izq, clave);
    }
    else if (clave > nodo->dni) {
        nodo->der = eliminarNodoAVL(nodo->der, clave);
    }
    else {//ya se encontro la clave a eliminar
        struct Nodo* aux = nullptr;
        //nodo hoja
        if (nodo->izq == nullptr and nodo->der == nullptr) {
            delete nodo;
            return nullptr;
        }
        //nodo con solo hija der
        if (nodo->izq == nullptr) {
            aux = nodo->izq;
            delete nodo;
            return aux;
        }

        //nodo con solo hijo izq
        if (nodo->der == nullptr) {
            aux = nodo->der;
            delete nodo;
            return aux;
        }

        //nodo con dos hijos
        aux = nodoMinimo(nodo->der);
        nodo->dni = aux->dni;
        nodo->der = eliminarNodoAVL(nodo->der, aux->dni);

        //ACTUALIZAMOS ALTURA
        nodo->altura = 1 + max(altura(nodo->der), altura(nodo->izq));

        //ROTACIONES
        if (factor_balance(nodo) > 1 and factor_balance(nodo->izq)>=0) {
            return rotacionDerecha(nodo);
        }

        if (factor_balance(nodo)<-1 and factor_balance(nodo->der) <=0) {
            return rotacionIzquierda(nodo);
        }

        if (factor_balance(nodo) > 1 and factor_balance(nodo->izq) <0) {
            nodo->izq = rotacionIzquierda(nodo->izq);
            return rotacionDerecha(nodo);
        }

        if (factor_balance(nodo) <-1 and factor_balance(nodo->der) >0) {
            nodo->der = rotacionDerecha(nodo->der);
            return rotacionIzquierda(nodo);
        }

        return nodo;
    }
}

int contar_nodos(struct Nodo* nodo) {
    if (nodo == nullptr) return 0;
    return 1+ contar_nodos(nodo->izq) + contar_nodos(nodo->der);
}

struct Nodo* buscar_k_enesimo(struct Nodo* nodo, int k) {
    if (nodo == nullptr) return nullptr;

    int nodos_izq = contar_nodos(nodo->izq);
    if (k==nodos_izq+1) return nodo;
    if (k<= nodos_izq) return buscar_k_enesimo(nodo->izq, k);

    return  buscar_k_enesimo(nodo->der, k-(nodos_izq+1));
}