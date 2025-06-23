#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

struct State {
    int cost = INT_MAX;
    int from_coupon = -1;
    bool used_coupon = false;
};

struct Result {
    int total_cost;
    int k1;  // оставшиеся купоны
    int k2;  // использованные купоны
    std::vector<int> days;  // дни использования купонов
};

Result dp_alg(int n, const std::vector<int>& prices) {
    using namespace std;

    vector<vector<State>> dp(n + 1, vector<State>(n + 2)); // dp[день][кол-во купонов]
    dp[0][0].cost = 0;

    for (int day = 1; day <= n; ++day) {
        int price = prices[day];

        for (int c = 0; c <= n; ++c) {
            // 1. Покупаем за деньги
            if (price > 100) {
                if (c >= 1 && dp[day - 1][c - 1].cost != INT_MAX) {
                    int new_cost = dp[day - 1][c - 1].cost + price;
                    if (new_cost < dp[day][c].cost) {
                        dp[day][c].cost = new_cost;
                        dp[day][c].from_coupon = c - 1;
                        dp[day][c].used_coupon = false;
                    }
                }
            } else {
                if (dp[day - 1][c].cost != INT_MAX) {
                    int new_cost = dp[day - 1][c].cost + price;
                    if (new_cost < dp[day][c].cost) {
                        dp[day][c].cost = new_cost;
                        dp[day][c].from_coupon = c;
                        dp[day][c].used_coupon = false;
                    }
                }
            }

            // 2. Используем купон
            if (c + 1 <= n && dp[day - 1][c + 1].cost != INT_MAX) {
                int new_cost = dp[day - 1][c + 1].cost;
                if (new_cost < dp[day][c].cost) {
                    dp[day][c].cost = new_cost;
                    dp[day][c].from_coupon = c + 1;
                    dp[day][c].used_coupon = true;
                }
            }
        }
    }

    // Поиск оптимального количества купонов с минимальной стоимостью
    int min_cost = INT_MAX;
    int best_coupons = -1;

    for (int c = 0; c <= n; ++c) {
        if (dp[n][c].cost < min_cost) {
            min_cost = dp[n][c].cost;
            best_coupons = c;
        } else if (dp[n][c].cost == min_cost && c > best_coupons) {
            best_coupons = c;
        }
    }

    // Восстановление пути
    std::vector<int> used_coupon_days;
    int day = n;
    int c = best_coupons;

    while (day > 0) {
        const State& s = dp[day][c];
        if (s.used_coupon) {
            used_coupon_days.push_back(day);
        }
        c = s.from_coupon;
        --day;
    }

    std::sort(used_coupon_days.begin(), used_coupon_days.end());

    Result res;
    res.total_cost = min_cost;
    res.k2 = used_coupon_days.size();
    res.k1 = best_coupons;
    res.days = std::move(used_coupon_days);
    return res;
}

int main() {
    using namespace std;

    int n;
    cin >> n;

    vector<int> prices(n + 1);  // 1-based indexing
    for (int i = 1; i <= n; ++i) {
        cin >> prices[i];
    }

    Result result = dp_alg(n, prices);

    cout << result.total_cost << '\n';
    cout << result.k1 << ' ' << result.k2 << '\n';
    for (int day : result.days) {
        cout << day << '\n';
    }

    return 0;
}
