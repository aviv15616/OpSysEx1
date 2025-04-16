#include <stdio.h>
#include <stdlib.h>
#include <complex.h>
#include "mandelbrot.h"

int main() {
    double real, imag;

    while (1) {
        printf("Enter real and imaginary parts: ");
        if (scanf("%lf %lf", &real, &imag) != 2) {
            fprintf(stderr, "Usage: Enter two real numbers (e.g., -1.627 -0.001)\n");
            break;
        }        

        // תנאי יציאה: 0 0
        if (real == 0 && imag == 0) {
            printf("Terminating due to input 0 + 0i (which is obviously in the mandelbrot set)\n");
            break;
        }

        complex double c = real + imag * I;

        if (is_in_mandelbrot(c, 1000)) {
            printf("%f + %fi is in the Mandelbrot set\n", real, imag);
        } else {
            printf("%f + %fi is not in the Mandelbrot set\n", real, imag);
        }
    }

    return 0;
}
