#include <iostream>
#include <vector>

std::vector<int> Reversed(const std::vector<int>& v) {
    auto reversed = v;

    if (!reversed.empty()) {
        auto l = begin(reversed);
        auto r = end(reversed) - 1;

        while (l < r) {
            std::swap(*l++, *r--);
        }
    }

    return reversed;
}

int main() {
    std::vector<int> numbers{1, 2, 3, 4};

    for (const auto& v: Reversed(numbers)) {
        std::cout << v << ' ';
    }

    std::cout << std::endl;

    return 0;
}
