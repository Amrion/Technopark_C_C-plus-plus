#include "gtest/gtest.h"

extern "C" {
    #include "main.h"
}

TEST(TIMER, NULL_ARG) {
    EXPECT_EQ(1, timer(nullptr, nullptr));
}

TEST(TIMER, NULL_ARG) {
    EXPECT_EQ(1, timer(nullptr, nullptr));
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}