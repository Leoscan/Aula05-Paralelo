#include <stdio.h>
#include <stdlib.h>
#include <omp.h>


int main() {
    const int SIZE = 10;
    int vector[SIZE]; 
    int pares = 0; 
    int impares = 0;
    
    for (int i = 0; i < SIZE; i++) {
        vector[i] = rand();
    }

    #pragma omp parallel for
    for (int i = 0; i < SIZE; i++) {
        if (vector[i] % 2 == 0) {
            #pragma omp atomic
            pares++;
        } else {
            #pragma omp atomic
            impares++;
        }
    }

    printf("Número de pares: %d\n", pares);
    printf("Número de ímpares: %d\n", impares);

    return 0;
}
