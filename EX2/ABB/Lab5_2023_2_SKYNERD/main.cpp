#include "funcionesSkynerd.hpp"


/*
 * ELEMENTO: int id - char flag(S/N)
 */

// • Se sabe que cada nodo del árbol guarda un flag si es SkyNerd (S) o no (N), además de un
// número id del servidor el cual sirve para el ordenamiento del ABB
// • El servidor inteligente cuenta con una defensa formada por los servidores hijos de este
// subárbol
// • Para vencer a este servidor debe seguir los siguientes pasos:
// o Ubicar dentro del ABB al servidor nocivo, pero sin pasar por ningún servidor hijo de
// este.
// o Una vez ubicado SkyNerd se debe eliminar la red de servidores hijos que lo
// defienden, pero la única forma de quitar estos servidores es primero dejarlo sin hijos
// y luego recién proceder con la eliminación del nodo. Este proceso se debe a que al
// igual que SkyNerd los servidores hijos de cada nodo sirven de defensa del servidor
// padre.


int main() {

    struct ArbolBinarioBusqueda arbol;
    construir(arbol);

    insertar(arbol, {100,'N'});
    insertar(arbol, {50,'N'});
    insertar(arbol, {150,'N'});
    insertar(arbol, {25,'N'});
    insertar(arbol, {75,'N'});
    insertar(arbol, {125,'S'});
    insertar(arbol, {175,'N'});
    insertar(arbol, {200,'N'});
    insertar(arbol, {110,'N'});
    insertar(arbol, {140,'N'});
    insertar(arbol, {105,'N'});
    insertar(arbol, {115,'N'});
    insertar(arbol, {130,'N'});

    cout <<cant_Niveles(arbol)<<endl;
    // imprimir_nivel_enter(arbol);  --> SALIO MAL, XD
    struct NodoArbolBinarioBusqueda* skynerd =encontrarSkynerd(arbol);
    recorrerPreOrden(arbol);
    cout<<endl;
    skynerd = encontrarSkynerdIterativo(arbol);
    cout<<endl;
    cout<<"PostOrden: ";
    recorridoPostOrdenIterativo(arbol);
    cout<<endl;
    cout<<"InOrden: ";
    recorridoInOrdenIterativo(arbol);
    cout<<endl;

    cout<<"Skynerd es : "<< skynerd->elemento.id<<endl;
    cout<<"PostOrden: "<<endl;
    eliminar_subArbol(arbol,skynerd);

    return 0;
}