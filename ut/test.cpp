#include <gtest/gtest.h>

int sm(int a, int b) {
    return a + b;
}

TEST(SumTest, Basic) {
    EXPECT_EQ(sm(2, 2), 4);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}