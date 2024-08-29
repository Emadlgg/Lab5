#include <stdio.h>
#include <omp.h>

// Función para calcular el factorial de un número
long long factorial(int n) {
    long long result = 1;
    for (int i = 2; i <= n; i++) {
        result *= i;
    }
    return result;
}

// Función para generar la serie de Fibonacci hasta el n-ésimo término
void fibonacci(int n) {
    long long a = 0, b = 1, temp;
    printf("Serie de Fibonacci: ");
    for (int i = 1; i <= n; i++) {
        printf("%lld ", a);
        temp = a;
        a = b;
        b = temp + b;
    }
    printf("\n");
}

// Función para encontrar el máximo en un arreglo
int find_max(int arr[], int size) {
    int max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

int main() {
    int num = 10; // Para el cálculo de factorial y Fibonacci
    int arr[] = {3, 8, 1, 9, 2, 10, 15, 7, 5}; // Arreglo para encontrar el máximo
    int size = sizeof(arr) / sizeof(arr[0]);

    // Ejecuta las tres funciones en paralelo utilizando omp sections
    #pragma omp parallel sections
    {
        #pragma omp section
        {
            long long fact_result = factorial(num);
            printf("Factorial de %d es: %lld\n", num, fact_result);
        }

        #pragma omp section
        {
            fibonacci(num);
        }

        #pragma omp section
        {
            int max_result = find_max(arr, size);
            printf("El maximo en el arreglo es: %d\n", max_result);
        }
    }

    return 0;
}
