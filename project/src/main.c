#include <stdio.h>
#include "../include/main.h"

int main() {
    printf("Hello, World!\n");
    int i = 0;
    for (; i < 7; ++i) {
        printf("%d", i);
    }
    printf("%d", i);
    return 0;
}
