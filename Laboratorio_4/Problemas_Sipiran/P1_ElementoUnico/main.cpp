#include <iostream>
using namespace std;

/// BÚSQUEDA DEL ELEMENTO UNICO DEL ARREGLO

///Dado un arreglo ordenado en el cual todos los elementos aparecen
///dos veces y un elemento aparece una sola vez. Encontrar el
///elemento que aparece una sola vez. El algoritmo debe tener
///complejidad O(log n).

int EncuentraElementoUnico(int* arr, int inicio, int fin){


    //cuando encuentro el medio lo que sobra son dos grupos impares
    //si uno de los elementos del grupo impar es igual al medio, signifca que los demás elementos estan en pares
    //si el elemento de la derecha no es igual significa que ese numero o es unico o su par está al otro lado, de todas maneras
    //de todos modos signifca que su par está en el grupo impar, y tambien el elemento unico está ahi
    int medio = (inicio + fin) / 2;
    if (inicio == medio) return inicio;
    //si la izquierda adyacente es igual, entonces
    if (arr[medio+1] != arr[medio] and ) {
        //se va a la derecha
        cout<<"Se va para el grupo de la derecha"<<medio+1<<" hasta "<<fin<<endl;;
        return EncuentraElementoUnico(arr, medio+1, fin);
    }
    //si la derecha adyacente es igual se va a la izquierda
    else if (arr[medio] == arr[medio+1]) {
        cout<<"Se va para el grupo de la izquierda desde "<<inicio<<" hasta "<<medio-1<<endl;
        return EncuentraElementoUnico(arr,inicio, medio-1);
    }
    else return arr[medio];
}

///Antes del elemento unico: Primer-elemento (indice par) - segundo-elemento (indice impar)
///Despues del elemento unico: Primero-elemento (indice impar)   segundo-elemento(indice par)
///
///

// MOD           0 1 0 1 0 1 0 1 0 1 0

int main() {//   0 1 2 3 4 5 6 7 8 9 10
    int arr[] = {1,1,3,3,5,5,7,7,4,8,8}; //la cantidad del arreglo siempre es impar si el elemento unico sigue dentro
    int n= sizeof(arr)/sizeof(arr[0]);

    int unico = EncuentraElementoUnico(arr, 0, n-1);
    cout << unico << endl;
    return 0;
}