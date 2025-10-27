#include <iostream>
using namespace std;

///TEMA: DIVIDE Y VENCERÁS
///
///MergeSort: Es un algoritmo de ordenamiento
///Consiste en dividir en dos parte, cada parte ordenarla y luego fusionarlo

//Todo: Para fusionar creamos dos arreglos auxiliares y lo unimos todo en otro auxiliar pero más grande
//Todo: Al final pasamos al arreglo real lo que guardamos en el arr auxiliar ordenado
void Merge(int *arr, int n, int inicio_1, int fin_1,int inicio_2, int fin_2) {

    //TODO: creamos el primer arr aux, donde pasamos la primera mitad ordenada
    int longitud1 = fin_1 - inicio_1 +1; // si tengo indices: 0,1,2 -> longitud = 3 <>(2-0)+1
    int aux1[longitud1+1]; //el +1 es porque le ponemos una tapa con un valor mayor como INT_MAX
    int k=0; //indice del nuevo arr aux, que si debe iniciar en cero
    for (int i=inicio_1;i<=fin_1;i++) { //pasamos la data de la priemra mitad al arr-aux1
        aux1[k++] = arr[i];
    }

    //TODO: creamos el primer arr aux, donde pasamos la primera mitad ordenada
    int longitud2 = fin_2 - inicio_2 +1;
    int aux2[longitud2+1];
    k=0;
    for (int i=inicio_2;i<=fin_2;i++) {
        aux2[k++] = arr[i];
    }

    //TODO: Creamos el arreglo aux total para juntar ambos ordenados en su totalidad
    int longitud_total = longitud1 + longitud2;
    int aux_total[longitud_total];
    int i=0, j=0;
    k=0;
    //van pasando recorriendo y comparando entre los menores y lo pasan ordenado al nuevo arreglo
    //hasta que uno de los aux llegue al final
    //solo quiero recorrer del 0 al 2 por ejemplo, longitud 3, pero reservé 4. Pero es correcto: i<longitud
    while (i<longitud1 and j<longitud2) {
        if (aux1[i]<aux2[j]) {
            aux_total[k++] = aux1[i];
            i++;
        }else {
            aux_total[k++] = aux2[j];
            j++;
        }
    }
    //todo: ya pasó todo aux1, falta aux2
    if (i == longitud1) for (;j<longitud2;j++) aux_total[k++] = arr[j];
    //todo: ya pasó todo aux2, falta aux1
    if (j == longitud2) for (;i<longitud1;i++) aux_total[k++] = arr[i];

    //TODO: Pasamos el arr_total al arreglo real
    k=inicio_1;
    for (int m=0;m<longitud_total;m++) {
        arr[k++] = aux_total[m];
    }
}

// divide, ordena, fusiona . Termina cuando ya no pueda dividir (inicio = fin o inicio > fin)
void  MergeSort(int* arr, int n, int inicio, int fin) {
    //Ya no puede dividirlo, es el unico asi que está ordenado, pero la accion de fusionar
    //es un void asi que creo que no se devuelve nada
    if (inicio>= fin) return;

    //divido y le asigno la recursion a cada mitad
    int medio = (inicio+fin)/2;
    MergeSort(arr,n,inicio,medio);
    MergeSort(arr,n,medio+1,fin);

    //fusiono
    Merge(arr, n, inicio,medio, medio+1, fin);
}

int main() {
    int arr[] = {31 , 5 , 14 , 7 , 12 , 1 , 21 , 18};
    int n = sizeof(arr) / sizeof(arr[0]);
    MergeSort(arr, n, 0, n-1);
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}