#include <stdio.h>
#include <stdlib.h>
#include <complex.h>
#include <string.h>
#include "mandelbrot.h"

#define BUFFER_SIZE 100

int main() {
    double real, imag;
    char buffer[BUFFER_SIZE];

    while (1) {
        printf("Enter real and imaginary parts: ");
        if (!fgets(buffer, sizeof(buffer), stdin)) {
            fprintf(stderr, "Input error.\n");
            break;
        }

        // ננסה לקרוא בדיוק שני מספרים ובודקים שאין עוד זבל אחריהם
        char extra;
        int num_read = sscanf(buffer, "%lf %lf %c", &real, &imag, &extra);

        if (num_read == EOF) {
            fprintf(stderr, "Input error.\n");
            break;
        }
        
        if (num_read != 2) {
            fprintf(stderr, "Usage: Enter two real numbers (e.g., -1.627 -0.001)\n");
            continue; // במקום לעצור, פשוט לבקש קלט מחדש
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
