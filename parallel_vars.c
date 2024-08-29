#include <stdio.h>
#include <omp.h>

int main() {
    int n = 10;  // Tamaño del ciclo
    int variable1 = 0;  // Variable compartida
    int variable2;  // Variable privada

    // Ciclo paralelo con omp parallel for
    #pragma omp parallel for shared(variable1) private(variable2)
    for (int i = 0; i < n; i++) {
        // variable2 es privada, cada hilo tiene su propia copia
        variable2 = i * 2;
        variable1 += i;  // Acceso compartido a variable1   

        // Imprimir los valores dentro del ciclo
        printf("Iteracion %d: variable1 = %d, variable2 = %d (Thread %d)\n", i, variable1, variable2, omp_get_thread_num());
    }

    // Imprimir el valor final de variable1 después del ciclo
    printf("Valor final de variable1 = %d\n", variable1);

    return 0;
}
