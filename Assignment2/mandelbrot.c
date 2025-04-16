#include <stdio.h>
#include <stdlib.h>
#include <complex.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>

#define M 2

bool is_in_mandelbrot(complex double c, int N) {
    complex double z = 0;  // נכון: מתחילים מ־z0 = 0
    for (int i = 0; i < N; i++) {
        if (cabs(z) > M) {
            return false;  // הסדרה בורחת => לא שייך
        }
        z = z * z + c;
    }
    return true;  // שייך לקבוצה
}


int main(int argc, char* argv[]) {
    // --help או קלט חסר
    if ((argc == 2 && strcmp(argv[1], "--help") == 0) || argc < 3) {
        fprintf(stderr, "Usage: %s <real> <imag> [N (optional)]\n", argv[0]);
        return 1;
    }

    // קלט מהשורה: real imag [N]
    double real = atof(argv[1]);
    double imag = atof(argv[2]);
    int N = (argc >= 4) ? atoi(argv[3]) : 1000; // ברירת מחדל ל־100 איטרציות

    // יוצרים את המספר המרוכב c
    double complex c = real + imag * I;

    // בדיקה
    if (is_in_mandelbrot(c, N)) {
        printf("%f + %fi is in the Mandelbrot set\n", real, imag);
    } else {
        printf("%f + %fi is not in the Mandelbrot set\n", real, imag);
    }

    return 0;
}
