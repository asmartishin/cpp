#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

int main() {
    std::size_t n;
    std::cin >> n;
    std::vector<int> v(n);

    for (auto &i: v) {
        std::cin >> i;
    }

    std::sort(std::begin(v), std::end(v), [](const int& lhs, const int& rhs) {
        return abs(lhs) < abs(rhs);
    });

    for (const auto& i: v) {
        std::cout << i << ' ';
    }

    std::cout << std::endl;

    return 0;
}
