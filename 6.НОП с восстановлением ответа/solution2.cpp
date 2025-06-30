// наибольшую общую подпоследовательность (НОП)

#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> solution(int n, const std::vector<int>& nv, int m, const std::vector<int>& mv) {
    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(m + 1, 0));

    // Строим таблицу LCS
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (nv[i - 1] == mv[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    // Восстановление ответа из таблицы
    std::vector<int> lcs;
    int i = n, j = m;
    while (i > 0 && j > 0) {
        if (nv[i - 1] == mv[j - 1]) {
            lcs.push_back(nv[i - 1]);
            --i;
            --j;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            --i;
        } else {
            --j;
        }
    }

    std::reverse(lcs.begin(), lcs.end());
    return lcs;
}

int main() {
    using namespace std;

    int n;
    cin >> n;
    vector<int> nv(n);
    for (int i = 0; i < n; ++i) {
        cin >> nv[i];
    }

    int m;
    cin >> m;
    vector<int> mv(m);
    for (int i = 0; i < m; ++i) {
        cin >> mv[i];
    }

    vector<int> res = solution(n, nv, m, mv);
    for (int el : res) cout << el << ' ';
    cout << '\n';

    return 0;
}
