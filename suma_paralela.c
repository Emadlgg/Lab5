#include <stdio.h>
#include <omp.h>

#define N 1000000  // Define N como una constante grande

int main() {
    int sum = 0;  // Variable para acumular la suma
    double start_time, end_time;

    // Inicia la medición de tiempo
    start_time = omp_get_wtime();

    // Ciclo for paralelo con cláusula reduction para acumular la suma
    #pragma omp parallel for reduction(+:sum)
    for (int i = 1; i <= N; i++) {
        sum += i;
    }

    // Finaliza la medición de tiempo
    end_time = omp_get_wtime();

    // Muestra el resultado de la suma y el tiempo de ejecución
    printf("La suma de los primeros %d numeros naturales es: %d\n", N, sum);
    printf("Tiempo de ejecucion: %f segundos\n", end_time - start_time);

    return 0;
}
