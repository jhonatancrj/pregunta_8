#include <stdio.h>
#include <omp.h>

int main() {
    const int N = 9; // Número de términos en la serie
    const int M = 4; // Número de vectores (procesadores)
    
    int series[N]; // Serie de números
    int i, num_threads;
    
    // Definir el número de hilos a usar
    omp_set_num_threads(M);
    
    // Distribuir los cálculos entre los hilos
    #pragma omp parallel private(i)
    {
        num_threads = omp_get_num_threads();
        int thread_id = omp_get_thread_num();
        
        // Calcular los elementos de la serie para este hilo
        for (i = thread_id; i < N; i += num_threads) {
            series[i] = (i + 1) * 2;
        }
    }
    
    // Imprimir la serie generada
    printf("Serie generada:\n");
    for (i = 0; i < N; i++) {
        printf("%d ", series[i]);
    }
    printf("\n");
    
    return 0;
}