//
// Created by binny on 03/12/2025.
//

#include "funcionesSkynerd.hpp"


int contar_niveles_recursivo(struct NodoArbolBinarioBusqueda *nodo) {
    if (nodo == nullptr) return 0;
    int niveles_izq=0, niveles_der=0, max_nivel =0;
    if (!esNodoVacio(nodo->izquierda))
        niveles_izq = contar_niveles_recursivo(nodo->izquierda);
    if (!esNodoVacio(nodo->derecha))
        niveles_der = contar_niveles_recursivo(nodo->derecha);

    max_nivel = (niveles_izq > niveles_der) ? niveles_izq : niveles_der;
    return max_nivel+1;
}

int cant_Niveles(const struct ArbolBinarioBusqueda &arbol) {
    return contar_niveles_recursivo(arbol.raiz);
}

void imprimir_nivel_enter(const struct ArbolBinarioBusqueda &arbol) {
    if (esNodoVacio(arbol.raiz)) {
        cout << "Árbol vacío" << endl;
        return;
    }

    struct Cola cola;
    construir(cola);

    struct ElementoCola c_elemento {arbol.raiz};
    encolar(cola, c_elemento);

    int altura = cant_Niveles(arbol);
    int nivel_actual = 0;

    while (!esColaVacia(cola) && nivel_actual < altura) {
        int cant_nodos_nivel = longitud(cola);
        bool hay_nodos_reales = false;

        // Calcular espaciado para este nivel
        int espacios_antes = (1 << (altura - nivel_actual - 1)) - 1; // 2^(altura-nivel-1) - 1
        int espacios_entre = (1 << (altura - nivel_actual)) - 1;     // 2^(altura-nivel) - 1

        // Espacios antes del primer nodo
        for (int i = 0; i < espacios_antes; i++) {
            cout << "   ";
        }

        for (int i = 0; i < cant_nodos_nivel; i++) {
            c_elemento = desencolar(cola);

            // Si el nodo es NULL, imprimir espacio vacío
            if (esNodoVacio(c_elemento.nodo)) {
                cout << "   ";

                // Encolar NULL para los hijos (mantener estructura)
                struct ElementoCola vacio {nullptr};
                encolar(cola, vacio);
                encolar(cola, vacio);
            }
            else {
                // Imprimir el nodo real (centrado en 3 caracteres)
                cout << setw(3) << c_elemento.nodo->elemento.id;
                hay_nodos_reales = true;

                // Encolar hijo izquierdo (o NULL si no existe)
                if (!esNodoVacio(c_elemento.nodo->izquierda)) {
                    struct ElementoCola c_izq {c_elemento.nodo->izquierda};
                    encolar(cola, c_izq);
                } else {
                    struct ElementoCola vacio {nullptr};
                    encolar(cola, vacio);
                }

                // Encolar hijo derecho (o NULL si no existe)
                if (!esNodoVacio(c_elemento.nodo->derecha)) {
                    struct ElementoCola c_der {c_elemento.nodo->derecha};
                    encolar(cola, c_der);
                } else {
                    struct ElementoCola vacio {nullptr};
                    encolar(cola, vacio);
                }
            }

            // Espacios entre nodos (excepto después del último)
            if (i < cant_nodos_nivel - 1) {
                for (int j = 0; j < espacios_entre; j++) {
                    cout << "   ";
                }
            }
        }

        cout << endl;
        nivel_actual++;

        // Detener si ya no hay nodos reales
        if (!hay_nodos_reales) break;
    }
}




struct NodoArbolBinarioBusqueda* encontrar_skynerd_recursivo(struct NodoArbolBinarioBusqueda* nodo) {
    if (nodo == nullptr) return nullptr;
    if (nodo->elemento.flag == 'S') return nodo;
    struct NodoArbolBinarioBusqueda * sky_izq = encontrar_skynerd_recursivo(nodo->izquierda);
    struct NodoArbolBinarioBusqueda * sky_der = encontrar_skynerd_recursivo(nodo->derecha);
    if (!esNodoVacio(sky_izq)) return sky_izq;
    else if (!esNodoVacio(sky_der))  return sky_der;
    else return nullptr;
}

struct NodoArbolBinarioBusqueda * encontrarSkynerd(const struct ArbolBinarioBusqueda &arbol) {

    struct NodoArbolBinarioBusqueda * skynerd =  encontrar_skynerd_recursivo(arbol.raiz);
    cout << skynerd->elemento.id << " es Skynerd" << endl;
    return skynerd;
}

//TODO: DEBE SER PREORDEN
struct NodoArbolBinarioBusqueda * encontrarSkynerdIterativo(const struct ArbolBinarioBusqueda &arbol) {
    struct Pila pila;
    construir(pila);

    struct ElementoPila p_elemento{arbol.raiz};
    apilar(pila, p_elemento);


    while (!esPilaVacia(pila)) {

        p_elemento = desapilar(pila);
        struct NodoArbolBinarioBusqueda * nodo_actual = p_elemento.nodo;
        //PROCESAMIENTO
        if (nodo_actual->elemento.flag == 'S') return nodo_actual;
        //--------------

        cout<<nodo_actual->elemento.flag<<"-"<<nodo_actual->elemento.id<<"  ";
        //
        if (!esNodoVacio(nodo_actual->derecha)) {
            struct ElementoPila p_izq{nodo_actual->derecha};
            apilar(pila, p_izq);
        }
        if (!esNodoVacio(nodo_actual->izquierda)) {
            struct ElementoPila p_izq{nodo_actual->izquierda};
            apilar(pila, p_izq);
        }

    }

    return nullptr;
}

struct NodoArbolBinarioBusqueda* encontrarPadreRecursivo(struct NodoArbolBinarioBusqueda *nodo,struct NodoArbolBinarioBusqueda *skynerd) {
    if (nodo==nullptr or nodo==skynerd) return nullptr;

    if (nodo->izquierda == skynerd or nodo->derecha == skynerd) return nodo;

    NodoArbolBinarioBusqueda* padre_izq = encontrarPadreRecursivo(nodo->izquierda, skynerd);
    NodoArbolBinarioBusqueda* padre_der = encontrarPadreRecursivo(nodo->derecha, skynerd);

    return (padre_izq) ? padre_izq : padre_der;

}

struct NodoArbolBinarioBusqueda* encontrarPadre(const struct ArbolBinarioBusqueda &arbol,struct NodoArbolBinarioBusqueda *skynerd) {
    return encontrarPadreRecursivo(arbol.raiz, skynerd);
}




void eliminarArbolPostOrdenIterativo(struct NodoArbolBinarioBusqueda* nodo_eliminar) {
    if (esNodoVacio(nodo_eliminar)) {
        return;
    }

    struct Pila pila_hijas, pila_padres;
    construir(pila_hijas);
    construir(pila_padres);

    struct ElementoPila p_elemento{nodo_eliminar};
    apilar(pila_hijas, p_elemento);

    // Llenar pila2 con orden inverso a postorden
    while (!esPilaVacia(pila_hijas)) {
        p_elemento = desapilar(pila_hijas);
        apilar(pila_padres, p_elemento);

        if (!esNodoVacio(p_elemento.nodo->izquierda)) {
            struct ElementoPila p_izq{p_elemento.nodo->izquierda};
            apilar(pila_hijas, p_izq);
        }

        if (!esNodoVacio(p_elemento.nodo->derecha)) {
            struct ElementoPila p_der{p_elemento.nodo->derecha};
            apilar(pila_hijas, p_der);
        }
    }

    // Eliminar en orden postorden
    while (!esPilaVacia(pila_padres)) {
        p_elemento = desapilar(pila_padres);
        cout << "Eliminando nodo: " << p_elemento.nodo->elemento.id << endl;
        delete p_elemento.nodo;
    }
}

void eliminar_subArbol(struct ArbolBinarioBusqueda &arbol,struct NodoArbolBinarioBusqueda *nodo_eliminar) {
    // Validación: si el nodo a eliminar es nulo, no hacer nada
    if (esNodoVacio(nodo_eliminar)) {
        cout << "No hay nodo para eliminar" << endl;
        return;
    }

    // CASO ESPECIAL: Si estamos eliminando la raíz del árbol
    if (arbol.raiz == nodo_eliminar) {
        cout << "Eliminando árbol completo desde la raíz" << endl;
        eliminarArbolPostOrdenIterativo(nodo_eliminar);
        arbol.raiz = nullptr;  // El árbol queda vacío
        return;
    }

    // CASO GENERAL: Eliminar un subárbol que no es la raíz

    // Paso 1: Encontrar el padre del nodo a eliminar
    struct NodoArbolBinarioBusqueda* padre =
        encontrarPadreRecursivo(arbol.raiz, nodo_eliminar);

    // Paso 2: Desconectar el nodo del árbol (actualizar puntero del padre)
    if (!esNodoVacio(padre)) {
        if (padre->izquierda == nodo_eliminar) {
            padre->izquierda = nullptr;  // Desconectar hijo izquierdo
            cout << "Desconectando subárbol izquierdo del nodo "
                 << padre->elemento.id << endl;
        }
        else if (padre->derecha == nodo_eliminar) {
            padre->derecha = nullptr;    // Desconectar hijo derecho
            cout << "Desconectando subárbol derecho del nodo "
                 << padre->elemento.id << endl;
        }
    }

    // Paso 3: Eliminar el subárbol completo en postorden
    cout << "Eliminando subárbol del nodo " << nodo_eliminar->elemento.id << endl;
    eliminarArbolPostOrdenIterativo(nodo_eliminar);
}

void recorridoInOrdenIterativo(const struct ArbolBinarioBusqueda &arbol) {
    struct Pila pila;
    construir(pila);

    struct NodoArbolBinarioBusqueda* nodo_actual = arbol.raiz;
    while (!esPilaVacia(pila) or !esNodoVacio(nodo_actual)) {

        //todo: evaluamos que el nodo al que nos pasamos
        // tenga algo que apilar al irnos a la izquierda
        // Si llegamos aun nodo nulo, se salta el while y de frente desapila
        // es como dar un salto al otro nivel que estaba apilar. Ahora si
        //todo:repetimos (apilar ful iz, desapilo ult izq, si ult_izq tiene derecha-> apilo,
        // SIEMPRE me paso a la derecha, aunque sea nullptr, porque eso va a ser condicion para saltarnos el while


        //IR A LA IZQUIERDA LO MAS POSIBLE, APILANDO TODO
        while (!esNodoVacio(nodo_actual)) {
            struct ElementoPila p_elemento{nodo_actual};
            apilar(pila, p_elemento);
            nodo_actual = nodo_actual->izquierda;
        }

        //DESAPILAR Y PROCESAR
        struct ElementoPila p_elemento = desapilar(pila);
        //es necesario, porque sino se queda en el nullptr que tenia al salir del bucle, el sig nullptr despues de la ultima izq
        nodo_actual = p_elemento.nodo;

        cout<<p_elemento.nodo->elemento.id<<" ";

        //IR A LA DERECHA - Nota: si no actualizabamos el actual, luego cuando haciamos der, era null->der (CRASH)
        nodo_actual = nodo_actual->derecha;
    }

}

void recorridoPostOrdenIterativo(const struct ArbolBinarioBusqueda &arbol) {
    struct Pila pila_hijos, pila_padres;
    construir(pila_hijos);
    construir(pila_padres);

    struct ElementoPila p_elemento{arbol.raiz};
    apilar(pila_hijos, p_elemento);

    //TODO: Esto es solo el proceso de llenado de la pila de padres. Aqui aun no se procesa
    while (!esPilaVacia(pila_hijos)) {
        //sacamos uno de los hijos y lo tratamos como un nuevo padre
        p_elemento = desapilar(pila_hijos);

        //APILAMOS EN LA PILA DE HIJOS LOS HIJOS DEL NUEVO PADRE
        if (!esNodoVacio(p_elemento.nodo->izquierda)) {
            struct ElementoPila p_izq{p_elemento.nodo->izquierda};
            apilar(pila_hijos, p_izq);
        }

        if (!esNodoVacio(p_elemento.nodo->derecha)) {
            struct ElementoPila p_der{p_elemento.nodo->derecha};
            apilar(pila_hijos, p_der);
        }

        //LUEGO DE VERIFICAR SI APILAR SUS HIJOS, LO APILAMOS EN LA PILA DE PADRES
        apilar(pila_padres, p_elemento);
    }

    //TODO: DESAPILAMOS LA PILA PADRE Y AHORA SI PODEMOS PROCESARLO
    while (!esPilaVacia(pila_padres)) {
        p_elemento = desapilar(pila_padres);
        cout<<p_elemento.nodo->elemento.id<<"  ";
    }

}


