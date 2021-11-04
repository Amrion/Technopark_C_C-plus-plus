#include <dlfcn.h>
#include "main.h"

typedef int (*myfunc)(const char*, int size);

int main() {
    char* arr = (char*) malloc(SIZE);
    if (!arr) {
        return 1;
    }

    FILE* fp = fopen("../symbols.txt", "r");
    if (!fp) {
        free(arr);

        return 1;
    }

    if (fgets(arr, SIZE - 2, fp) == NULL) {
        free(arr);
        fclose(fp);

        return 1;
    }

    printf("Последовательная реализация\n");
    if (timer(find_max, arr, SIZE) == 1) {
        free(arr);
        fclose(fp);

        return 1;
    }

    void *library = dlopen("../cmake-build-debug/libfind_parallel_lib.so", RTLD_LAZY);
    if (!library) {
        dlclose(library);
        free(arr);
        fclose(fp);

        return 1;
    }

    printf("Параллельная реализация\n");

    myfunc find_max_parallel = dlsym(library, "find_max");
    if (dlerror() != NULL)  {
        free(arr);
        dlclose(library);
        fclose(fp);

        return 1;
    }

    if (timer(find_max_parallel, arr, SIZE) == 1) {
        dlclose(library);
        free(arr);
        fclose(fp);

        return 1;
    }

    dlclose(library);
    free(arr);
    fclose(fp);
    return 0;
}
