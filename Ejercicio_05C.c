#include <stdio.h>
#include <omp.h>
#include <stdlib.h>

#define SIZE 1000000   // Definir un tamaño adecuado para los vectores
#define KEY_COUNT 100  // Definir un número adecuado de claves

int main() {
    int DBin[SIZE];
    int keys[KEY_COUNT];
    int DBout[SIZE];
    int DBoutIndex = 0;

    // Inicializar los vectores DBin y keys con algunos valores
    for (int i = 0; i < SIZE; i++) {
        DBin[i] = rand() % 1000;  // Valores aleatorios en DBin
    }
    for (int i = 0; i < KEY_COUNT; i++) {
        keys[i] = rand() % 1000;  // Valores aleatorios en keys
    }

    #pragma omp parallel sections
    {
        #pragma omp section
        {
            // Productor: busca claves en DBin
            for (int i = 0; i < SIZE; i++) {
                for (int j = 0; j < KEY_COUNT; j++) {
                    if (DBin[i] == keys[j]) {
                        #pragma omp critical
                        {
                            DBout[DBoutIndex++] = i; // Guardar la posición en DBout
                        }
                        break;  // Salir del bucle de claves cuando se encuentra una coincidencia
                    }
                }
            }
        }

        #pragma omp section
        {
            // Consumidor: podría realizar alguna operación con DBout
            // Este es un ejemplo simple, donde sólo imprimimos las posiciones
            #pragma omp critical
            {
                for (int i = 0; i < DBoutIndex; i++) {
                    printf("Clave encontrada en posición: %d\n", DBout[i]);
                }
            }
        }
    }

    return 0;
}
