#include <gtest/gtest.h>
#include "median.hpp"

TEST(MEDIAN_TEST, FromCodeRun) {
    EXPECT_EQ(median(1, 2, 3), 2);
    EXPECT_EQ(median(1000, -1000, 0), 0);
    EXPECT_EQ(median(3, 1, 3), 3);
}

TEST(MEDIAN_TEST, All_equals) {
    EXPECT_EQ(median(0, 0, 0), 0);
    EXPECT_EQ(median(1, 1, 1), 1);
    EXPECT_EQ(median(1000, 1000, 1000), 1000);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
