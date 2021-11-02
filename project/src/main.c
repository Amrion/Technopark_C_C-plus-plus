#include <dlfcn.h>
#include "main.h"

int (*myfunc)(const char*, int size);

int main() {
    char* arr = (char*) calloc(SIZE, sizeof (char ));
    if (unlikely(!arr)) {
        return 1;
    }

    FILE* fp = fopen("../symbols.txt", "r");
    if (unlikely(!fp)) {
        free(arr);

        return 1;
    }

    if (fgets(arr, SIZE + 1, fp) == NULL) {
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
    if (unlikely(!library)) {
        free(arr);
        fclose(fp);

        return 1;
    }

    printf("Параллельная реализация\n");

    *(void**) (&myfunc) = dlsym(library, "find_max");
    if (timer(myfunc, arr, SIZE) == 1) {
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
