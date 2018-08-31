#include <iostream>
#include <vector>

void Reverse(std::vector<int>& v) {
    if (v.empty()) {
        return;
    }

    auto l = begin(v);
    auto r = end(v) - 1;

    while (l < r) {
        std::swap(*l++, *r--);
    }
}

int main() {
    std::vector<int> numbers{1, 2, 3, 4};

    Reverse(numbers);

    for (const auto& v: numbers) {
        std::cout << v << ' ';
    }

    std::cout << std::endl;

    return 0;
}
