// нахождение наибольшей общей непрерывной подпоследовательности (подстроки)

#include <vector>
#include <iostream>

std::vector<int> solution(int n, const std::vector<int> &nv, int m, const std::vector<int> &mv) {

    std::vector<std::vector<int>> dp(n, std::vector<int>(m, 0));
    int maxi = -1, maxj = -1, max_el = -999999;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (nv[i] == mv[j]) ++dp[i][j];
            if (i - 1 >= 0 && j - 1 >= 0) dp[i][j] += dp[i - 1][j - 1];

            if (dp[i][j] > max_el) {
                maxi = i;
                maxj = j;
                max_el = dp[i][j];
            }
        }
    }


    // std::cout << std::endl;
    // for (int i = 0; i < n; ++i) {
    //     for (int j = 0; j < m; ++j) {
    //         std::cout << dp[i][j] << ' ';
    //     }
    //     std::cout << std::endl;
    // }

    // std::cout << std::endl;
    std::vector<int> answ{};
    for (int j = maxj; j >= 0; --j) {
        int el = mv[maxj - j];
        --max_el;
        if (max_el < 0) break;
        answ.push_back(el);
        // std::cout << el << ' ';
    }

    return answ;
}

int main() {
    using namespace std;

    int n;
    cin >> n;
    vector<int> nv(n, 0);
    for (int i = 0; i < n; ++i) {
        cin >> nv[i];
    }

    int m;
    cin >> m;
    vector<int> mv(m, 0);
    for (int i = 0; i < m; ++i) {
        cin >> mv[i];
    }

    auto res = solution(n, nv, m, mv);
    for (int el : res) cout << el << ' ';

    return 0;
}