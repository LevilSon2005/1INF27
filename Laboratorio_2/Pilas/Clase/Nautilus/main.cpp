#include <iostream>
using namespace std;
/*S: Guardan en pila (apila), desapilan e imprimir
 * B: Solo apilan
 */

void muestra_Recorrido(char *instrucciones, int n) {
    struct Pila aux;
    construir(aux);

    for (int i = 0; i < n; i++) {
        dato.numero = i+1; //el numero
        apilar(aux, dato); //sea S o B igual siempre se apila
        if (instrucciones[i]=='S' or i==n) { //cuando encuentra S desapila todos los de abajo
            while (not esPilaVacia(aux)) {
                cout<<desapilar(aux).numero;
            }
            cout<<endl;
        }
    }
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}