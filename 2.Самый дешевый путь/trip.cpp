
#include <vector>
#include <algorithm>
#include "trip.hpp"

int low_cost_trip(int n, int m, int **mat) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (i == 0 && j == 0) continue;
            int sy = INT_MAX, sx = INT_MAX;
            if (i - 1 >= 0) sy = mat[i - 1][j];
            if (j - 1 >= 0) sx = mat[i][j - 1];
            mat[i][j] += std::min(sy, sx);
        }
    }

    return mat[n - 1][m - 1];
}