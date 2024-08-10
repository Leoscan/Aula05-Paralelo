#include <stdio.h>
#include <omp.h>

int main() {
    const int SIZE = 100;
    int vector[SIZE];

    for (int i = 0; i < SIZE; i++) {
        vector[i] = i;
    }

    #pragma omp parallel
    {
        // Etapa 1: Multiplicar todos os elementos por 2
        #pragma omp for
        for (int i = 0; i < SIZE; i++) {
            vector[i] *= 2;
        }

        // Sincronização: aguardar todas as threads completarem a Etapa 1
        #pragma omp barrier

        // Etapa 2: Adicionar 10 a todos os elementos
        #pragma omp for
        for (int i = 0; i < SIZE; i++) {
            vector[i] += 10;
        }
    }

    for (int i = 0; i < SIZE; i++) {
        printf("vector[%d] = %d\n", i, vector[i]);
    }

    return 0;
}
