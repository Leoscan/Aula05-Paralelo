#include <stdio.h>
#include <stdlib.h>
#include <omp.h>


int main() {
    int i;
    const int SIZE = 1000000;
    const int MAX_VALUE = 100;
    int *vector = (int *)malloc(SIZE * sizeof(int));
    int histogram[MAX_VALUE] = {0};

    for (i = 0; i < SIZE; i++) {
        vector[i] = rand() % MAX_VALUE;
    }

    #pragma omp parallel for
    for (i = 0; i < SIZE; i++) {
        int value = vector[i];
        #pragma omp critical
        {
            histogram[value]++;
        }
    }

    for (i = 0; i < MAX_VALUE; i++) {
        printf("Valor %d: %d\n", i, histogram[i]);
    }

    free(vector);
    return 0;
}
