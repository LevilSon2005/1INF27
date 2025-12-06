#include "TAD.hpp"
#include "funciones.hpp"
#include <iostream>
using namespace std;

int main() {

    ABB arbol;
    construir(arbol);

    //implementacion
    int dnis[N]={72649318, 50823147, 81234567, 40987654, 65012345, 94561237, 30124598};
    for (int i = 0; i < N; i++) {
        Nodo *nodo;
        nodo=insertarAVL(arbol.raiz,dnis[i]);
        //cout<<"Insertar "<<nodo->dni<<endl;
    }
    recorrerEnOrden(arbol);
    cout << endl;

    int total=contarNodos(arbol.raiz);

    if(total%2==1){
        int k=(total/2)+1;
        Nodo *mediana=buscar_k_enesimo(arbol.raiz,k);
        cout<<"La mediana es: "<<mediana->dni<<endl;
    }else{
        int k1=(total/2);
        int k2=(total/2)+1;
        Nodo *med1=buscar_k_enesimo(arbol.raiz,k1);
        Nodo *med2=buscar_k_enesimo(arbol.raiz,k2);

        double mediana=(med1->dni+med2->dni)/2.0;
        cout<<"La mediana es: "<<mediana<<endl;
    }


    arbol.raiz = eliminarNodoAVL(arbol.raiz, 50823147);
    recorrerEnOrden(arbol);

    cout << endl;

    return 0;
    // TIP See CLion help at <a href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>. Also, you can try interactive lessons for CLion by selecting 'Help | Learn IDE Features' from the main menu.
}