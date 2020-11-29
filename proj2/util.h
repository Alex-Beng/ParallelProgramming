#include <stdlib.h>

double RandDouble(double min, double max) {
    double range = (max - min); 
    double div = RAND_MAX / range;
    return min + (rand() / div);
}

int InCircle(double x, double y) {
    if (x*x + y*y <= 1) {
        return 1;
    }
    else {
        return 0;
    }
}
