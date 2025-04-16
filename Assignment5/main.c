#include <stdio.h>
#include <stdlib.h>
#include "max_sub_arr.h"

int main(int argc, char* argv[]) {
    if (argc != 3) {
        printf("Usage: %s <seed> <size>\n", argv[0]);
        return 1;
    }

    int seed = atoi(argv[1]);
    int size = atoi(argv[2]);

    int* arr = generate_random_array(seed, size);
    if (!arr) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }
    

    if (size <= 1000) {
        int max_sum_n3 = max_sub_arr_n3(arr, size);
        printf("O(n^3): %d\n", max_sum_n3);
    } else {
        printf("O(n^3): skipped (input too large)\n");
    }

    if (size <= 10000) {
        int max_sum_n2 = max_sub_arr_n2(arr, size);
        printf("O(n^2): %d\n", max_sum_n2);
    } else {
        printf("O(n^2): skipped (input too large)\n");
    }

    int max_sum_n = max_sub_arr_n(arr, size);
    printf("O(n):   %d\n", max_sum_n);

    free(arr);
    return 0;
}
