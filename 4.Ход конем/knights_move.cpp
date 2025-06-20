#include <vector>
#include <climits>
#include "knights_move.hpp"

int knights_move(int n, int m, std::vector<std::vector<int>> &v) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int c1 = INT_MAX, c2 = INT_MAX;
            if (i - 2 >= 0 && j - 1 >= 0) c1 = v[i - 2][j - 1];
            v[i][j] += (c1 != INT_MAX) ? c1 : 0;
            if (i - 1 >= 0 && j - 2 >= 0) c2 = v[i - 1][j - 2];
            v[i][j] += (c2 != INT_MAX) ? c2 : 0;
        }
    }
    return v[n - 1][m - 1];
}


std::vector<std::vector<int>> zeros(int n, int m) {
    std::vector<std::vector<int>> matrix(n, std::vector<int>(m));
    matrix[0][0] = 1;
    return matrix;
}