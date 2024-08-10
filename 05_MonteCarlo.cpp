#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <time.h>

int main() {
    const int PONTOS = 1000;
    int i, contagem = 0;
    double x, y;
    double pi;

    srand(time(NULL));

    #pragma omp parallel
    {
        int local_count = 0;

        #pragma omp for private(x, y)
        for (i = 0; i < PONTOS; i++) {
            x = (double)rand() / RAND_MAX; 
            y = (double)rand() / RAND_MAX; 

            if (x * x + y * y <= 1.0) {
                local_count++;
            }
        }

        #pragma omp atomic
        contagem += local_count;

        #pragma omp barrier
    }

    pi = 4.0 * contagem / PONTOS;

    printf("Valor estimado de PI: %f\n", pi);

    return 0;
}