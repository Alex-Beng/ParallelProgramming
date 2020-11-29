#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#include "util.h"

int main(int argc, char const *argv[]) {
    if (argc != 2) {
        printf("usage: [exec] [point num]\n");
        return -1;
    }
    int pnt_nums;
    sscanf(argv[1], "%d", &pnt_nums);

    srand (time(NULL));

    int pnt_in_cc = 0;

    clock_t begin = clock();
    for (int i=0; i<pnt_nums; i++) {
        double x = RandDouble(0, 1);
        double y = RandDouble(0, 1);
        if (InCircle(x, y)) {
            pnt_in_cc += 1;
        }
    }
    clock_t end = clock();
    clock_t time_spent = end - begin;

    double pi = pnt_in_cc*1.0/pnt_nums;
    pi *= 4.0;
    printf("%d points get %lf take %ld ms\n", pnt_nums, pi, time_spent);
    return 0;
}