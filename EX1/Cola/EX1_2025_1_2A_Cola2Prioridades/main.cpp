#include <iostream>
#include "BibliotecaCola/funcionesCola.h"
#include "BibliotecaCola/Cola.h"
using namespace std;

int Prioridad(char prioridad) {
    if (prioridad == 'B' or prioridad == 'C' ) return 2;
    else return 1;
}

//TODO: RECUERDA ACTUALIZAR LAST1
void insertarPrimeraCola(struct NodoCola* nuevo_nodo, struct Cola &cola,bool esConsecutivo) {
    //todo: primer nodo de la cola total
    if (esColaVacia(cola)) {
        cola.inicio = nuevo_nodo;
        cola.fin = nuevo_nodo;
        cola.last1 = nuevo_nodo;
        cola.longitud1++;
        return;
    }

    //todo: solo existe cola 2 - primer nodo Cola1
    if (cola.last1 == nullptr) {
        //insertar al inicio - ultima vez cambio inicio
        nuevo_nodo->siguiente = cola.inicio;
        cola.inicio = nuevo_nodo;
        cola.last1 = nuevo_nodo;
        cola.longitud1++;
        return;
    }

    //TODO: si existe cola 1
    //todo: si solo existe cola 1
    if (cola.last1 == cola.fin) {
        cola.last1->siguiente = nuevo_nodo;
        cola.last1 =nuevo_nodo;
        cola.fin = nuevo_nodo;
    }
    // todo: si existe cola1 y existe cola2
    else {
        nuevo_nodo->siguiente = cola.last1->siguiente;
        cola.last1->siguiente = nuevo_nodo;
        cola.last1= nuevo_nodo;
    }
    cola.longitud1++;
}

//TODO: Si existe cola2 - se tiene que analizar si son consecutivos
void encolarCola2_SiExisteCola2(struct Cola &cola, struct NodoCola* nuevo_nodo, bool esConsecutivo) {

    //primero validamos si el anterior es igual
    if (cola.fin->elemento.prioridad == nuevo_nodo->elemento.prioridad) {
        esConsecutivo = true;
    }

    //todo: si existe SOLO cola2
    if (cola.last1 == nullptr) { //debemos actualizar fin
        if (esConsecutivo) {
            //todo: Solo existe cola2 -  solo hay consecutivos
            if (cola.inicio_aislados != nullptr) {
                cola.fin->siguiente = nuevo_nodo;
                cola.last_consecutivo = nuevo_nodo;
                cola.fin = nuevo_nodo;
            }
            //todo: existe cola2 - solo hay aislados - primer consecutivo
            else {

            }
        }

        if (esConsecutivo and cola.inicio_aislados != nullptr) {

        }else if (esConsecutivo and cola.inicio_aislados == nullptr) {
            cola.fin->siguiente = nuevo_nodo;
        }
    }
}

void insertarSegundaCola(struct NodoCola* nuevo_nodo, struct Cola &cola, bool esConsecutivo) {
    //todo: primer nodo de la cola total
    if (esColaVacia(cola)) {
        cola.inicio = nuevo_nodo;
        cola.inicio_aislados = nuevo_nodo;
        cola.fin = nuevo_nodo;
        cola.longitud2++;
        //como es el primer nodo de cola 2, por mientras está aislado
        esConsecutivo = false;
        return;
    }

    //todo: si solo existe cola1 - primer nodo para cola2 - se agrega de frente
    if (cola.last1 == cola.fin) {
        cola.fin->siguiente = nuevo_nodo;
        cola.fin = nuevo_nodo;
        cola.inicio_aislados = nuevo_nodo;
        cola.longitud2++;
        //como es el primer nodo de cola 2, por mientras está aislado
        esConsecutivo = false;
        return;
    }

    //TODO: Si existe cola2 - se tiene que analizar si son consecutivos
    //todo: solo existe cola2
    encolarCola2_SiExisteCola2(cola, nuevo_nodo,esConsecutivo);
    //todo: existe cola1 y cola2
    encolarCola2_SiExisteCola1_y_Cola2(cola, nuevo_nodo, esConsecutivo);
    cola.longitud2++;
}

void encolarPrioridad(struct ElementoCola elemento,struct Cola &colaPrioridad,int prioridad, bool esConsecutivo) {
    //todo: creamos el nuevo nodo
    struct NodoCola* nuevo_nodo;
    nuevo_nodo = new struct NodoCola;
    nuevo_nodo->elemento = elemento;
    nuevo_nodo->siguiente = nullptr;

    if (prioridad == 1) insertarPrimeraCola(nuevo_nodo, colaPrioridad,esConsecutivo);
    if (prioridad == 2) insertarSegundaCola(nuevo_nodo, colaPrioridad,esConsecutivo);
}



int main() {
    struct Cola colaPrioridad;
    construir (colaPrioridad);
    bool grupo = false;

    struct ElementoCola c1 ={1,10,'B',grupo};
    struct ElementoCola c2 ={2,20,'A',grupo };
    struct ElementoCola c3 ={3,15,'B',grupo};
    struct ElementoCola c4 ={4,12,'B',grupo};
    struct ElementoCola c5 ={5,5,'C',grupo};
    struct ElementoCola c6 ={6,6,'A',grupo};
    struct ElementoCola c7 ={7,8,'C',grupo};
    struct ElementoCola c8 ={8,4,'C',grupo};
    struct ElementoCola c9 ={9,2,'B',grupo};

    encolarPrioridad(c2,colaPrioridad,Prioridad(c2.prioridad),grupo );

    return 0;
}