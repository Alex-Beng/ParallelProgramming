#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <omp.h>

#include "util.h"

int main(int argc, char const *argv[]) {
    if (argc != 3) {
        printf("usage: [exec] [point num] [thread num]\n");
        return -1;
    }
    int pnt_nums, thread_nums;
    sscanf(argv[1], "%d", &pnt_nums);
    sscanf(argv[2], "%d", &thread_nums);

    srand (time(NULL));

    // Use reduce to protect pnt_in_cc
    int pnt_in_cc = 0;
    // int* pnt_in_cc = (int*)malloc(sizeof(int)*thread_nums);

    clock_t begin = clock();
    int i;
    #pragma omp parallel for num_threads(thread_nums) reduction(+:pnt_in_cc)
        for (i=0; i<pnt_nums; i++) {
            double x = RandDouble(0, 1);
            double y = RandDouble(0, 1);
            if (InCircle(x, y)) {
                pnt_in_cc += 1;
            }
        }
    
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

    double pi = pnt_in_cc*1.0/pnt_nums;
    pi *= 4.0;
    printf("%d points get %lf take %lfs\n", pnt_nums, pi, time_spent);
    return 0;
}
