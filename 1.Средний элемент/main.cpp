#include <iostream>
#include "median.hpp"

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int a[3];
    for (int i = 0; i < 3; ++i) std::cin >> a[i];
    std::cout << median(a[0], a[1], a[2]);
}
