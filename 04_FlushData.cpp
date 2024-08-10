#include <stdio.h>
#include <omp.h>


int main() {
    int data = 0;
    int flag = 0;

    #pragma omp parallel num_threads(5)
    {
        int thread_id = omp_get_thread_num();

        if (thread_id == 0) {
            for (int i = 1; i <= 10; i++) {
                #pragma omp critical
                {
                    data = i;
                    flag = 1;
                }
                
                #pragma omp flush(data, flag)
                printf("Produtor: Dado produzido %d\n", data);
                while (flag == 1) {
                    #pragma omp flush(flag)
                }
            }
        } else {
            while (1) {
                while (flag == 0) {
                    #pragma omp flush(flag)
                }

                #pragma omp flush(data, flag)
                printf("Consumidor %d: Dado consumido %d\n", thread_id, data);

                #pragma omp critical
                {
                    flag = 0;
                }
                #pragma omp flush(flag)
                if (data == 10) break;
            }
        }
    }

    return 0;
}
