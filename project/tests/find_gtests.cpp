#include "gtest/gtest.h"

extern "C" {
    #include <dlfcn.h>
    #include "main.h"
}

TEST(FIND_C, NULL_ARR) {
    EXPECT_EQ(-1, find_max(nullptr, 100));
}

TEST(FIND_C, NULL_SIZE) {
    int size = 0;
    char* arr = (char *) calloc(2, sizeof (char));

    EXPECT_EQ(0, find_max(arr, size));

    free(arr);
}

TEST(FIND_C, SIZE_10000) {
    int size = 10000;
    char* arr = (char *) calloc(size, sizeof (char));

    FILE* fp = fopen("../symbols.txt", "r");
    fgets(arr, size + 1, fp);


    EXPECT_EQ(184, find_max(arr, size));

    free(arr);
    fclose(fp);
}

TEST(FIND_C, SIZE_1000000) {
    int size = 1000000;
    char* arr = (char *) calloc(size, sizeof (char));

    FILE* fp = fopen("../symbols.txt", "r");
    fgets(arr, size + 1, fp);

    EXPECT_EQ(264, find_max(arr, size));

    free(arr);
    fclose(fp);
}

TEST(FIND_C, SIZE_100000000) {
    int size = 100000000;
    char* arr = (char *) calloc(size, sizeof (char));

    FILE* fp = fopen("../symbols.txt", "r");
    fgets(arr, size + 1, fp);

    EXPECT_EQ(417, find_max(arr, size));

    free(arr);
    fclose(fp);
}

class FIND_P : public ::testing::Test
{
protected:
    void SetUp() {
        int (*myfunc)(const char*, int size);

        void *library = dlopen("../cmake-build-debug/libfind_parallel_lib.so", RTLD_LAZY);
        *(void**) (&myfunc) = dlsym(library, "find_max");
    }
    void TearDown() {}
};

TEST_F(FIND_P, NULL_ARR) {
    EXPECT_EQ(-1, find_max(nullptr, 100));
}

TEST_F(FIND_P, NULL_SIZE) {
    int size = 0;
    char* arr = (char *) calloc(2, sizeof (char));

    EXPECT_EQ(0, find_max(arr, size));

    free(arr);
}

TEST_F(FIND_P, SIZE_10000) {
    int size = 10000;
    char* arr = (char *) calloc(size, sizeof (char));

    FILE* fp = fopen("../symbols.txt", "r");
    fgets(arr, size + 1, fp);


    EXPECT_EQ(184, find_max(arr, size));

    free(arr);
    fclose(fp);
}

TEST_F(FIND_P, SIZE_1000000) {
    int size = 1000000;
    char* arr = (char *) calloc(size, sizeof (char));

    FILE* fp = fopen("../symbols.txt", "r");
    fgets(arr, size + 1, fp);

    EXPECT_EQ(264, find_max(arr, size));

    free(arr);
    fclose(fp);
}

TEST_F(FIND_P, SIZE_100000000) {
    int size = 100000000;
    char* arr = (char *) calloc(size, sizeof (char));

    FILE* fp = fopen("../symbols.txt", "r");
    fgets(arr, size + 1, fp);

    EXPECT_EQ(417, find_max(arr, size));

    free(arr);
    fclose(fp);
}



