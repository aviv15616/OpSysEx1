#include <stdlib.h>  

// פונקציה ליצירת מערך אקראי בגודל size עם seed קבוע
// המערך כולל מספרים בטווח [-25, 74]
int* generate_random_array(int seed, int size) {
    srand(seed);  
    int* arr = malloc(size * sizeof(int));
    if (!arr) {
        return NULL;  // החזרת NULL אם הקצאת זיכרון נכשלה
    }

    for (int i = 0; i < size; ++i) {
        arr[i] = (rand() % 100) - 25;  // תוצאה בטווח [-25, 74]
    }

    return arr;
}
int max_sub_arr_n(int* arr, int size) {
    int max_sum = arr[0];
    int current_sum = 0;
    for (int i = 0; i < size; ++i) {
        current_sum += arr[i];
        if (current_sum > max_sum) {
            max_sum = current_sum;
        }
        if (current_sum < 0) {
            current_sum = 0;
        }
    }
    return max_sum;
}
int max_sub_arr_n2(int* arr, int size) {
    int max_sum = arr[0];
    for (int i = 0; i < size; ++i) {
        int sum = 0;
        for (int j = i; j < size; ++j) {
            sum += arr[j];
            if (sum > max_sum) {
                max_sum = sum;
            }
        }
    }
    return max_sum;
}
int max_sub_arr_n3(int* arr, int size) {
    int max_sum = arr[0];
    for (int i = 0; i < size; ++i) {
        for (int j = i; j < size; ++j) {
            int sum = 0;
            for (int k = i; k <= j; ++k) {
                sum += arr[k];
            }
            if (sum > max_sum) {
                max_sum = sum;
            }
        }
    }
    return max_sum;
}