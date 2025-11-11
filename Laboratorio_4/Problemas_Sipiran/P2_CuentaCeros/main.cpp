#include <iostream>
using namespace std;

/// 2. Dado un arreglo de 0’s y 1’s el cual tiene todos los 1’s primero
/// seguido de todos los 0’s. Encontrar el número de 0’s.
///
/// Ejemplos:
/// Entrada: {1, 1, 1, 0, 0, 0, 0}  -
/// Output: 4
///
/// Entrada: {1, 1, 1, 1, 1}  -
/// Salida: 0

//Nota: separo los casos de (inicio==fin) y (inicio > fin), porque en (inicio==fin) todavia es necesario analizar si
// es que es necesario aumentar en el contador, en cambio en el otro caso de frente solo debo parar
void cuentaCeros(int* arreglo, int inicio, int fin, int &contador) {
    if (inicio == fin) {
        if (arreglo[inicio] == 0) {
            cout << "Estoy en el indice : "<< inicio << " aumento el contado. Valor = " <<arreglo[inicio]<<endl;
            contador++;
        }
        return;
    }

    if (inicio > fin) return;

    int medio = (inicio + fin) / 2;
    if (arreglo[medio] == 1) {
        cuentaCeros(arreglo, medio+1, fin, contador);
    }
    else{//cuando: arreglo[medio]==0
        cuentaCeros(arreglo, inicio, medio-1, contador);
        cout << "Estoy en el indice : "<< medio << " aumento el contado. Valor = " <<arreglo[medio]<<endl;
        contador++;
        cuentaCeros(arreglo, medio+1, fin, contador);
    }

}

int main() {
    int arreglo[] = {1, 1, 1, 0, 0, 0, 0, 0, 0};
    int n = sizeof(arreglo) / sizeof(arreglo[0]);

    int contador =0;
    cuentaCeros(arreglo, 0, n-1, contador);
    cout << contador << endl;
    return 0;
}