#include <iostream>
using namespace std;
#include "BibliotecaCola/funcionesCola.h"
#include "BibliotecaCola/Cola.h"

///PROBLEMA DE ASCENSORES:
///
/// - Cada solicitud tiene: piso y direccion
/// - Un ascensor para subida y otro para bajada
/// - Solo se aceptan la siguiente solicitiud luego de que el ascensor se desencole
/// - Desde un mismo piso pueden pedirse las dos direcciones pero una DESPUES de otra - supongo que esto tbm sera en solicitudes diferentes
/// - Si alguien presiona el boton más de una vez, solo se ENCOLA UNA SOLICITUD
/// - Solo se encola para subida, aquellas que se solicitan que sea mayor que la que se encuentra
/// - Para subida es menor a mayor
/// - Para bajada es de mayor a menor. Si ingresa una nueva solicitud que es menor al minimo actual se añade al recrrodio,
/// - Para bajada es de mayor a menor
/// pero si lo que ingresa es  mayor al piso maximo en el recorrido de bajada, se atiende luego? -> se podria decir que solo se pone arriba y se anzaliza en nueva bajada
/// -


void encolarEnSeccionSubida(struct Cola &colaSubida, int n_sacar, int n_seccion, struct ElementoCola e) {

    //todo: si es que quiero encolar ordenado en el grupo de menores, pongo los mayores al final
    for (int i=0;i<n_sacar;i++) {
        struct ElementoCola temporal = desencolar(colaSubida);
        encolar(colaSubida, temporal);
    }

    //muevo al final los menores al elemento a encolar y encolo el elemento ahi paro
    bool posicionEncontrada = false;
    int cant_procesados=0;


    while (cant_procesados < n_seccion and !posicionEncontrada) {
        struct ElementoCola temporal = desencolar(colaSubida);
        if (temporal.piso < e.piso ) {
            encolar(colaSubida, temporal);
            cant_procesados++;
        }
        else {//quiero pare cuando encole en posicion correcta, lo demás será se movera en otra parte
            encolar(colaSubida, e);
            encolar(colaSubida, temporal);
            posicionEncontrada = true;
            cant_procesados++;
        }
    }

    // Mover el resto de la sección si aún no insertamos
    while (cant_procesados < n_seccion) {
        struct ElementoCola temporal = desencolar(colaSubida);
        encolar(colaSubida, temporal);
        cant_procesados++;
    }

    // Si nunca insertamos, va al final de la seccion
    if (!posicionEncontrada) {
        encolar(colaSubida, e);
    }

    //muevo lo de otra seccion al final
    int cant_falta_procesar = colaSubida.longitud - cant_procesados -1; //el 1 es por el que insertamos
    for (int i=0;i<cant_falta_procesar;i++) {
        struct ElementoCola temporal = desencolar(colaSubida);
        encolar(colaSubida, temporal);
    }

}


//de menor a mayor
void encolarOrdenadoSubida(struct Cola &colaSubida,int piso_actual ,struct ElementoCola e) {
    //si es el primer elemento se encola de frente
    if (esColaVacia(colaSubida)) {
        encolar(colaSubida, e);
        return;
    }

    //TODO: Debemos decidir si se encola en el grupo de los que son menores o mayores que el piso actual
    int n=colaSubida.longitud;
    int cantMayores = 0;
    int cantMenores =0;

    //Todo: averiguamos cuantos elementos son del primer grupo (los mayores) - aun es posible encolarlos en el recorrido de subida
    for (int i=0;i<n;i++) {
        struct ElementoCola temporal = desencolar(colaSubida);
        if (piso_actual < temporal.piso) cantMayores++;
        if (piso_actual > temporal.piso) cantMenores++;
        encolar(colaSubida, temporal);
    }

    //todo: primer grupo - se inserta ordenado en los pisos mayores
    if (e.piso > piso_actual) {
        encolarEnSeccionSubida(colaSubida, 0, cantMayores, e);
    }else {//todo: segundo grupo: encolar ordenado en el grupo pisos menores
        encolarEnSeccionSubida(colaSubida,cantMayores, cantMenores,e);
    }
}

void encolarEnSeccionBajada(struct Cola &colaBajada, int n_sacar, int n_seccion, struct ElementoCola e) {
    //todo: si es que quiero encolar ordenado en el grupo de mayores, pongo los menores al final
    //  Saltar elementos que no son de esta sección
    for (int i = 0; i < n_sacar; i++) {
        struct ElementoCola temporal = desencolar(colaBajada);
        encolar(colaBajada, temporal);
    }

    // Todo: Buscar posición e insertar (orden DESCENDENTE)
    bool posicionEncontrada = false;
    int cant_procesados = 0;

    while (cant_procesados < n_seccion && !posicionEncontrada) {
        struct ElementoCola temporal = desencolar(colaBajada);

        if (temporal.piso > e.piso) {  //tecnicamente solo cambia esto xd. Desperdicio copiar codigo. Tengo sueño ya fue F
            encolar(colaBajada, temporal);
            cant_procesados++;
        } else {
            encolar(colaBajada, e);
            encolar(colaBajada, temporal);
            posicionEncontrada = true;
            cant_procesados++;
        }
    }

    // todo: Procesar resto de la sección
    while (cant_procesados < n_seccion) {
        struct ElementoCola temporal = desencolar(colaBajada);
        encolar(colaBajada, temporal);
        cant_procesados++;
    }

    // Todo:  Si no insertó, va al final de la sección
    if (!posicionEncontrada) {
        encolar(colaBajada, e);
    }

    // Todo: Rotar resto (otras secciones)
    int cant_falta_procesar = colaBajada.longitud - cant_procesados - 1;
    for (int i = 0; i < cant_falta_procesar; i++) {
        struct ElementoCola temporal = desencolar(colaBajada);
        encolar(colaBajada, temporal);
    }
}

void encolarOrdenadoBajada(struct Cola &colaBajada, int piso_actual, struct ElementoCola e){
    //si es el primer elemento se encola de frente
    if (esColaVacia(colaBajada)) {
        encolar(colaBajada, e);
        return;
    }

    //TODO: Debemos decidir si se encola en el grupo de los que son menores o mayores que el piso actual
    int n=colaBajada.longitud;
    int cantMayores = 0;
    int cantMenores =0;

    //Todo: averiguamos cuantos elementos son del primer grupo (los mayores) - aun es posible encolarlos en el recorrido de subida
    for (int i=0;i<n;i++) {
        struct ElementoCola temporal = desencolar(colaBajada);
        if (piso_actual < temporal.piso) cantMayores++;
        if (piso_actual > temporal.piso) cantMenores++;
        encolar(colaBajada, temporal);
    }

    //todo: primer grupo - se inserta ordenado en los pisos menores
    if (e.piso < piso_actual) {
        encolarEnSeccionBajada(colaBajada, 0, cantMenores, e);
    }else {//todo: segundo grupo: encolar ordenado en el grupo pisos mayores
        encolarEnSeccionBajada(colaBajada,cantMenores, cantMayores,e);
    }
}

void encolarMovimientos(struct Cola &colaGeneral, struct Cola &colaSubida, struct Cola &colaBajada,
                        int piso_subida, int piso_bajada){

    while (!esColaVacia(colaGeneral)) {
        struct ElementoCola e = desencolar(colaGeneral);
        //PARA SUBIR
        if(e.movimiento==1) {
            encolarOrdenadoSubida(colaSubida,piso_subida, e);
        }
        // PARA SUBIR
        else {
            encolarOrdenadoBajada(colaBajada, piso_bajada, e);
        }
    }
}

int main() {
    struct Cola colaGeneral;
    construir(colaGeneral);

    struct ElementoCola e {1};
    encolar(colaGeneral, e);

    //Erasmo ve esta vaina y me fusila .... F nomas
    int cant_pisos=0, piso_subida=1,piso_bajada=1;
    cout<<"Ingrese la cantidad de pisos del edificio :";
    cin>>cant_pisos;
    cout<<"Movimientos de ascensor en un edificio de "<<cant_pisos<<" pisos: "<<endl;

    cout<<"La cola general de solicitudes tiene: ";
    imprimir_reves(colaGeneral, colaGeneral.inicio);
    cout<<endl;
    cout<<"Luego de asignar las solicitudes a cada ascensor se tiene: "<<endl;

    struct Cola colaSubida;
    struct Cola colaBajada;
    construir(colaSubida);
    construir(colaBajada);
    encolar(colaSubida, e);
    encolar(colaBajada, e);

    cout<<"Cola 1: ";
    imprimir_reves(colaSubida, colaSubida.inicio);
    cout<<endl;
    cout<<"Cola 2: ";
    imprimir_reves(colaBajada, colaBajada.inicio);
    cout<<endl;

    piso_subida = desencolar(colaSubida).piso;
    piso_bajada = desencolar (colaBajada).piso;
    desencolar(colaGeneral);
    cout<<"El ascensor 1 esta en el piso "<<piso_subida<<endl;
    cout<<"El ascensor 2 esta en el piso "<<piso_bajada<<endl;

    int cant_solicitudes=0;
    do {//todo: quiero que las primeras solicitudes se atiendan directo
        cout<<"Ingrese la cantidad de solicitudes: ";
        cin>>cant_solicitudes;
        for (int i=0;i<cant_solicitudes;i++) {
            struct ElementoCola elemento;
            cout<<"Solicitud "<<i+1<<" [numero_piso y direccion(1: sube, 0,: baja)]: ";
            cin>> elemento.piso;
            cin.get(); //para leer el espacio
            cin>>elemento.movimiento;
            encolar(colaGeneral, elemento);
        }
         if (cant_solicitudes>0) {
             cout<<"La cola general de solicitudes tiene: "<<endl;
             imprimir_reves(colaGeneral, colaGeneral.inicio);
             cout<<endl;
             //encola lo de la cola general en la cola de subida o bajada respectivamente
             encolarMovimientos(colaGeneral, colaSubida, colaBajada, piso_subida, piso_bajada);
         }
        cout<<"Luego de asignar las solicitudes a cada ascensor se tiene: "<<endl;
        cout<<" Cola 1: ";
        imprimir_reves(colaSubida, colaSubida.inicio);
        cout<<endl;
        cout<<"Cola 2: ";
        imprimir_reves(colaBajada, colaBajada.inicio);
        cout<<endl;
        if (!esColaVacia(colaSubida)) {
            piso_subida = desencolar(colaSubida).piso;
        }
        cout<<"El ascensor 1 esta en el piso"<<piso_subida<<endl;
        if (!esColaVacia(colaBajada)) {
            piso_bajada = desencolar(colaBajada).piso;
        }
        cout<<" El ascensor 2 esta en el piso "<<piso_bajada<<endl;

    } while ( !esColaVacia(colaSubida) or !esColaVacia(colaBajada));

    return 0;
}