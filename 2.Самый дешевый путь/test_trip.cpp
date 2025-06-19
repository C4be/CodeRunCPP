#include <gtest/gtest.h>
#include "trip.hpp"

TEST(NORM, FromCodeRun) {
    constexpr int n = 5;
    constexpr int m = 5;

    int init[n][m] = {
        {1, 1, 1, 1, 1},
        {3, 100, 100, 100, 100},
        {1, 1, 1, 1, 1},
        {2, 2, 2, 2, 1},
        {1, 1, 1, 1, 1}
    };

    int **mat = new int*[n];
    for (int i = 0; i < n; ++i) mat[i] = init[i];

    int res = low_cost_trip(n, m, mat);
    EXPECT_EQ(res, 11);

    delete[] mat;
}

TEST(NORM, Bound) {
    constexpr int n = 1;
    constexpr int m = 1;

    int init[n][m] = {{1}};

    int **mat = new int*[n];
    for (int i = 0; i < n; ++i) mat[i] = init[i];

    int res = low_cost_trip(n, m, mat);
    EXPECT_EQ(res, 1);

    delete[] mat;
}

TEST(NORM, Line) {
    constexpr int n = 1;
    constexpr int m = 5;

    int init[n][m] = {{1, 2, 3, 4, 5}};

    int **mat = new int*[n];
    for (int i = 0; i < n; ++i) mat[i] = init[i];

    int res = low_cost_trip(n, m, mat);
    EXPECT_EQ(res, 15);

    delete[] mat;
}

TEST(NORM, LineT) {
    constexpr int n = 5;
    constexpr int m = 1;

    int init[n][m] = {
        {1},
        {2},
        {3},
        {4},
        {5},
    };

    int **mat = new int*[n];
    for (int i = 0; i < n; ++i) mat[i] = init[i];

    int res = low_cost_trip(n, m, mat);
    EXPECT_EQ(res, 15);

    delete[] mat;
}

TEST(NORM, Diagonal1) {
    constexpr int n = 3;
    constexpr int m = 3;

    int init[n][m] = {
        {5, 1, 1},
        {1, 5, 1},
        {1, 1, 5},
    };

    int **mat = new int*[n];
    for (int i = 0; i < n; ++i) mat[i] = init[i];

    int res = low_cost_trip(n, m, mat);
    EXPECT_EQ(res, 13);

    delete[] mat;
}

TEST(NORM, Diagonal2) {
    constexpr int n = 3;
    constexpr int m = 3;

    int init[n][m] = {
        {1, 1, 5},
        {1, 5, 1},
        {5, 1, 1},
    };

    int **mat = new int*[n];
    for (int i = 0; i < n; ++i) mat[i] = init[i];

    int res = low_cost_trip(n, m, mat);
    EXPECT_EQ(res, 9);

    delete[] mat;
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}