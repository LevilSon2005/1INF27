#include <iostream>
#include <climits>
using namespace std;

///6. Dado un arreglo de enteros, encontrar el número de inversiones.
/// Una inversión es un par de elementos A[i] y A[j] tal que i < j y
/// A[i] > A[j].

//Recordatorio de la clase de Erasmo : hacer un caso base de una ruta que funciona. Para contar
// en arboles. Si quieres contar la cantidad de rutas(FB) que cumplen, se hace un caso base con
//las condiciones para que sea una ruta que cumple, eso dentro del of y return 1, y luego(abajo)
// se hace el return contar(izq) + contar(derecha).
//Esto se hace para evitar el uso de un contador como parametro por referencia



///Entonces, las inversiones se dividen naturalmente en tres grupos:

// 🟩 Inversiones internas en la izquierda
// Pares donde ambos índices están en la mitad izquierda
// → Ejemplo: (i, j) con inicio ≤ i < j ≤ medio
//
// 🟦 Inversiones internas en la derecha
// Pares donde ambos índices están en la mitad derecha
// → Ejemplo: (i, j) con medio+1 ≤ i < j ≤ fin
//
// 🟨 Inversiones cruzadas (“cruces”)
// Pares donde uno está en la izquierda y el otro en la derecha
// → Ejemplo: (i, j) con i ≤ medio < j
// → Aquí es donde los dos lados “se cruzan”, por eso el nombre “cruces”.



bool esInverso(int* arreglo, int i, int k) {
    return (i<k and arreglo[i] > arreglo[k]);
}

//esto es solo para recordar lo que hizo Cueva
void  Merge(int* arreglo, int  inicio, int medio,int fin) {

    //se pasa la primera mitad a una arreglo temporal_1
    int n_1 = medio - inicio + 1;
    int temporal_1[n_1];
    for (int i=0;i<n_1;i++) temporal_1[i] = arreglo[i+inicio];

    //se pasa la segunda mitad a un arreglo temporal_2
    int n_2 = fin - (medio +1)+1;
    int temporal_2[n_2];
    for (int i=0;i<n_2;i++) temporal_2[i] = arreglo[i+medio+1];

    //se ordena
    int p=0, q=0;
    for (int i=inicio;i<=fin;i++) { //todo: este for principal es para el arreglo original
        //todo: se le pasa el menor a los arreglos y se avanza al siguiente del menor en su arr temporal
        if (temporal_1[p] < temporal_2[q]) { //si el P es MENOR
            arreglo[i] = temporal_1[p];
            p++;
        }
        else { //si el Q es MENOR
            arreglo[i] = temporal_2[q];
            q++;
        }
    }
}

/*
                     [3, 8, 4, 2, 1]
                    /              \
            [3, 8, 4]              [2, 1]
            /        \              /    \
        [3, 8]      [4]          [2]    [1]
        /    \
      [3]    [8]
 */


/*TODO: Hay que tener en cuenta que llega ordenado para un izquierda y derecha de mas de un elemento.
 * La primera que entra en esta funcion(cuando ambos tienen un elemento si se ordena) y
 * se inserta de manera ordenada al arreglo, es por eso que el siguiente izquierda y derecha ya vienen
 * ordenados
 */

//aqui primero se pasa a dos arreglos temporales las dos parte, luego se ordena
void contarInversionesCruzadas(int* arreglo, int  inicio, int medio,int fin, int &contador) {

    //TODO: La primera vez(1 elemento viene normal), despues los temporales (izq y der) ya estan ordenados, porque el arreglo se ordenó

    //se pasa la primera mitad a una arreglo temporal_1
    int n_1 = medio - inicio + 1;
    int temporal_1[n_1+1];
    temporal_1[n_1]= INT_MAX; //al ultimo elemento se le añade un valor max
    for (int i=0;i<n_1;i++) temporal_1[i] = arreglo[i+inicio];

    //se pasa la segunda mitad a un arreglo temporal_2
    int n_2 = fin - (medio +1)+1;
    int temporal_2[n_2+1] ;
    temporal_2[n_2] = INT_MAX ;//al ultimo elemento se le añade un valor max
    for (int i=0;i<n_2;i++) temporal_2[i] = arreglo[i+medio+1];

    //se ordena
    int p=0, q=0;
    for (int i=inicio;i<=fin;i++) { //todo: este for principal es para el arreglo original
        //todo: se le pasa el menor a los arreglos y se avanza al siguiente del menor en su arr temporal
        if (temporal_1[p] <= temporal_2[q]) { //si el P es MENOR, el IGUAL tambien porque quieres ver si los del temporal_1 son mayores que el otro temporal
            //entonces debo avanzar al sig elemento mayor del temporal_1
            arreglo[i] = temporal_1[p];
            p++;
        }
        else { //si el Q es MENOR <> temporal_1[p] > temporal_2[q]
            arreglo[i] = temporal_2[q];
            q++;
            /*
             * temporal_1 = [5,15,20,22]
             * temporal_2 = [2,6,18,24]
             *
             *Si 5 es mayor que 2. Entonces lo que sigue de temporal_1 tambien será mayores porque está ordenado
             */
            contador+= (n_1 - p); //((n_1-1) - p) + 1  <> final - inicio +1;
        }
    }

    //Para lo de contarInversiones
    /*Nota: iba a contar despues de ordenar, pero ahora que me doy cuenta si ya lo ordeno, entonces ninguno cumpliria
     * lo de la inversion. Por eso se debe contar cuando ordenemos.
     */
}

void ContarInversiones(int* arreglo, int inicio, int fin, int &contador) {
    if (inicio == fin) return;
    if (inicio > fin) return;
    //serviria tbm un if(inicio >= fin) return;

    int medio = (inicio + fin) / 2;
    //todo: cuando ambos indices se encuentran en la izquierda
    ContarInversiones(arreglo, inicio, medio, contador);
    //todo: cuando ambos indices se encuentran en la derecha
    ContarInversiones(arreglo, medio+1, fin, contador);
    //todo: cuando un indice se encuentra en la izquierda y la otra en la derecha
    contarInversionesCruzadas(arreglo, inicio, medio, fin, contador);
}

int main() {
    int arreglo[] = {7,3,9,29,15,3,7,8};
    int n = sizeof(arreglo) / sizeof(arreglo[0]);

    int contador =0;
    ContarInversiones(arreglo, 0, n-1, contador);

    cout << "La cantidad de inversiones es: " << contador << endl;
    return 0;
}