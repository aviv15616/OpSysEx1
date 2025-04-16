#include "mandelbrot.h"
#include <math.h>

#define M 2

bool is_in_mandelbrot(complex double c, int N) {
    complex double z = 0;
    for (int i = 0; i < N; i++) {
        if (cabs(z) > M) {
            return false;
        }
        z = z * z + c;
    }
    return true;
}
