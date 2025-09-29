#include <iostream>
#include <cmath>
#include <climits>
using namespace std;

#define CANT_TABLAS 6
#define CANT_DISCOS 3

int tablas[CANT_TABLAS] = {150, 100, 80, 50, 120, 10};
int discos_originales[CANT_DISCOS] = {250, 200, 200};

void convertir_base(int num, int base, int n, int* cromosoma) {
    // Inicializar con ceros
    for (int j = 0; j < n; j++) {
        cromosoma[j] = 0;
    }

    int i = n-1;
    while (num > 0) {
        int cociente, residuo;
        while (num>0) {
            residuo = num % base;
            cociente = num / base;
            cromosoma[i] = residuo;
            num = cociente;
            i--;
        }
    }
}

bool es_asignacion_valida(int* cromosoma, int* discos_copia) {
    // Vuelvo a poner los datos originales
    for (int i = 0; i < CANT_DISCOS; i++) {
        discos_copia[i] = discos_originales[i];
    }

    // Verificar si la asignación es válida
    for (int k = 0; k < CANT_TABLAS; k++) {
        int disco_id = cromosoma[k];
        // Solo procesar si es un disco válido (0, 1 o 2)
        if (disco_id < CANT_DISCOS) {
            if (discos_copia[disco_id] < tablas[k]) {
                return false; // Si sobrepasa la capacidad del disco
            }
            discos_copia[disco_id] -= tablas[k];
        }
        // Si no es un disco válido no se hace nada? -- supondre que si -- F nomas
    }
    return true;
}

int hallarMinimo(int* discos) {
    int min_val = discos[0];
    for (int i = 1; i < CANT_DISCOS; i++) {
        if (discos[i] < min_val) {
            min_val = discos[i];
        }
    }
    return min_val;
}

int main() {
    int base = CANT_DISCOS; // Base 3 para 3 discos (0,1,2)
    int n = CANT_TABLAS;
    int cromosoma[CANT_TABLAS];
    int discos_copia[CANT_DISCOS];

    int max_minimo = INT_MIN;
    int mejor_cromosoma[CANT_TABLAS];


    int total_combinaciones = pow(base, n);

    //recorro todas las combinaciones
    for (int i = 0; i < total_combinaciones; i++) {
        //convierto a base 3
        convertir_base(i, base, n, cromosoma);
        if (es_asignacion_valida(cromosoma, discos_copia)) {
            int min_actual = hallarMinimo(discos_copia);
            if (min_actual > max_minimo) {
                max_minimo = min_actual;
                // Guardar la mejor asignación
                for (int j = 0; j < n; j++) {
                    mejor_cromosoma[j] = cromosoma[j];
                }
            }
        }
    }

    cout << "El minimo mas optimo es: " << max_minimo << endl;
    // Mostrar la asignación óptima
    for (int i = 0; i < CANT_DISCOS; i++) {
        cout << "Disco " << i+1 << ": ";
        for (int j = 0; j < CANT_TABLAS; j++) {
            if (mejor_cromosoma[j] == i) {
                cout << "Tabla-" << j+1 << "(" << tablas[j] << ") , ";
            }
        }
        cout<<endl;
        int uso = 0;
        for (int j = 0; j < CANT_TABLAS; j++) {
            if (mejor_cromosoma[j] == i) {
                uso += tablas[j];
            }
        }
    }
    
    return 0;
}