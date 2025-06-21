#include "cafe.hpp"

#include <iostream>

Answer dp_min_cost(int days, std::vector<int> &prises) {
    std::vector<std::vector<State>> dp(days + 1, std::vector<State>(days + 1));
    dp[0][0].cost = 0;

    for (int d = 1; d <= days; ++d) {
        for (int c = 0; c <= days; ++c) {
            int cant_add_cost = dp[d - 1][c].cost; // can't add coupons
            int add_cost = (c - 1 >= 0) ? dp[d - 1][c - 1].cost : INT_MAX; // add coupons
            int use_cost = (c + 1 < days) ? dp[d - 1][c + 1].cost : INT_MAX; // use coupons

            if (prises[d - 1] > 100) {
                int final_add_cost = (add_cost <= 300) ? prises[d - 1] + add_cost : INT_MAX;
                if (final_add_cost <= use_cost) {
                    dp[d][c].cost = final_add_cost;
                    dp[d][c].cnt_coupons = dp[d - 1][c - 1].cnt_coupons + 1;
                } else {
                    dp[d][c].cost = use_cost;
                    dp[d][c].from_coupons = c + 1;

                    dp[d][c].cnt_use_coupons = dp[d - 1][c + 1].cnt_use_coupons + 1;
                    dp[d][c].cnt_coupons = dp[d - 1][c + 1].cnt_coupons;
                    dp[d][c].coupons = dp[d - 1][c + 1].coupons;
                    dp[d][c].coupons.push_back(d);
                }
                // dp[d][c].cost = std::min(final_add_cost, use_cost);
            } else {
                int final_add_cost = (cant_add_cost <= 300) ? prises[d - 1] + cant_add_cost : INT_MAX;
                if (final_add_cost <= use_cost) {
                    dp[d][c].cost = final_add_cost;
                    dp[d][c].cnt_coupons = dp[d - 1][c].cnt_coupons;
                } else {
                    dp[d][c].cost = use_cost;
                    dp[d][c].from_coupons = c + 1;

                    dp[d][c].cnt_use_coupons = dp[d - 1][c + 1].cnt_use_coupons + 1;
                    dp[d][c].cnt_coupons = dp[d - 1][c + 1].cnt_coupons;
                    dp[d][c].coupons = dp[d - 1][c + 1].coupons;
                    dp[d][c].coupons.push_back(d);
                }
                // dp[d][c].cost = std::min(final_add_cost, use_cost);
            }
        }
    }

    // test
    std::cout << '\n';
    for (auto l : dp) {
        for (auto el : l) {
            std::cout << ((el.cost == INT_MAX) ? 301 : el.cost) << ' '; 
        }
        std::cout << '\n';
    }

    std::cout << '\n';
    for (auto l : dp) {
        for (auto el : l) {
            std::cout << ((el.from_coupons == INT_MAX) ? 301 : el.from_coupons) << ' '; 
        }
        std::cout << '\n';
    }

    State best_state{};
    for (auto last_day_cost : dp[days]) {
        if (last_day_cost.cost < best_state.cost || (last_day_cost.cost == best_state.cost && last_day_cost.from_coupons > best_state.from_coupons)) {
            best_state = last_day_cost;
        }
    }

    // test
    std::cout << '\n';
    std::cout << best_state.cnt_coupons - best_state.cnt_use_coupons << '\t' << best_state.cnt_use_coupons << '\t' << days << '\n';
    for (auto day : best_state.coupons) std::cout << day << ' ';
    std::cout << '\n';

    // return best_state.cost;

    Answer answ = Answer{};
    answ.k1 = best_state.cnt_coupons - best_state.cnt_use_coupons;
    answ.k2 = best_state.cnt_use_coupons;
    answ.final_cost = best_state.cost;
    answ.coupons = best_state.coupons;

    return answ;

    // int min_cost = INT_MAX;
    // for (auto last_day_cost : dp[days]) {
    //     min_cost = std::min(last_day_cost.cost, min_cost);
    // }

    // return min_cost;
}