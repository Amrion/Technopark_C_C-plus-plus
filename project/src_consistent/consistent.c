#include "main.h"

int find_max(const char* arr, int size) {
    if (unlikely(!arr)) {
        return -1;
    }

    int kol = 0, maxkol = 0;

    for (int i = 0; i < (size - 1); ++i) {
        if (arr[i] != arr[i + 1]) {
            ++kol;
        } else {
            ++kol;
            if (kol > maxkol) {
                maxkol = kol;
            }
            kol = 0;
        }
    }

    return maxkol;
}
