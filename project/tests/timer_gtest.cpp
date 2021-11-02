#include "gtest/gtest.h"

extern "C" {
    #include "main.h"
}

TEST(TIMER, NULL_ARG) {
    EXPECT_EQ(1, timer(nullptr, nullptr, 1));
}

TEST(TIMER, NOT_NULL_ARGS) {
    int size = 2;
    char* arr = (char*) calloc(size, sizeof (char ));

    EXPECT_EQ(0, timer(find_max, arr, size));
}