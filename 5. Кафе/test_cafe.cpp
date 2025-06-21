#include <gtest/gtest.h>
#include "cafe.hpp"

TEST(NORM, CodeRun) {
    int n = 5;
    std::vector<int> p{35, 40, 101, 59, 63};

    Answer ans = dp_min_cost(n, p);

    EXPECT_EQ(ans.final_cost, 235);
    EXPECT_EQ(ans.k1, 0);
    EXPECT_EQ(ans.k2, 1);

    EXPECT_EQ(ans.coupons[0], 5);
    
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}