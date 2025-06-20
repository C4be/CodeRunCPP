#include <gtest/gtest.h>
#include "knights_move.hpp"

TEST(NORM, OneMove1) {
    constexpr int n = 1;
    constexpr int m = 3;

    auto field = zeros(n, m);
    int answ = knights_move(n, m, field);

    EXPECT_EQ(answ, 0);
}

TEST(NORM, OneMove2) {
    constexpr int n = 3;
    constexpr int m = 1;

    auto field = zeros(n, m);
    int answ = knights_move(n, m, field);

    EXPECT_EQ(answ, 0);
}

TEST(NORM, TwoMove1) {
    constexpr int n = 4;
    constexpr int m = 4;

    auto field = zeros(n, m);
    int answ = knights_move(n, m, field);

    EXPECT_EQ(answ, 2);
}

TEST(NORM, TwoMove2) {
    constexpr int n = 3;
    constexpr int m = 3;

    auto field = zeros(n, m);
    int answ = knights_move(n, m, field);

    EXPECT_EQ(answ, 0);
}

TEST(NORM, CodeRun1) {
    constexpr int n = 3;
    constexpr int m = 2;

    auto field = zeros(n, m);
    int answ = knights_move(n, m, field);

    EXPECT_EQ(answ, 1);
}

TEST(NORM, CodeRun2) {
    constexpr int n = 31;
    constexpr int m = 34;

    auto field = zeros(n, m);
    int answ = knights_move(n, m, field);

    EXPECT_EQ(answ, 293930);
}



int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}