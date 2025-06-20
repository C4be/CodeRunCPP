#include <iostream>

#include "knights_move.hpp"

int main() {
    int n{}, m{};
    std::cin >> n >> m;
    auto v = zeros(n, m);
    std::cout << knights_move(n, m, v);
}