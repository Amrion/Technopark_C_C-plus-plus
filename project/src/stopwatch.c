#include "main.h"
#include <time.h>

int timer(int (*func)(const char* arr, int size), const char* arr, int size) {
    if (unlikely((!func) || (!arr))) {
        return 1;
    }
    clock_t start, stop;
    start = clock();

    int kol = func(arr, size);
    if (unlikely(kol == -1)) {
        return 1;
    }

    stop = clock();
    double time = (double)(stop - start) / CLOCKS_PER_SEC;

    if (printf("Количество последовательных символов = %d\n", kol) < 0) {
        return 1;
    }
    if (printf("Затраченное время = %lf\n", time) < 0) {
        return 1;
    }

    return 0;
}
