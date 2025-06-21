#include <iostream>

#include "cafe.hpp"

int main() {
	int n{};
	std::cin >> n;
	std::vector<int> p{};

	for (int i = 0; i < n; ++i) {
		int el; std::cin >> el;
        p.push_back(el);
	}

	Answer ans = dp_min_cost(n, p);
	std::cout << ans.final_cost << '\n';
	std::cout << ans.k1 << ' ' << ans.k2 << '\n';
	
	for (auto el : ans.coupons) {
		std::cout << el << '\n';
	}

	return 0;
}