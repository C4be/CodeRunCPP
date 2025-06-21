#ifndef CAFE_HPP
#define CAFE_HPP

#include <vector>
#include <climits>
#include <algorithm>

struct State {
    int cost = INT_MAX;
    int from_coupons = -1;
    int cnt_coupons = 0;
    int cnt_use_coupons = 0;
    std::vector<int> coupons{};
};

struct Answer {
    int final_cost{-1}, k1{-1}, k2{-1};
    std::vector<int> coupons{};
};

Answer dp_min_cost(int days, std::vector<int> &prises);

#endif // CAFE_HPP