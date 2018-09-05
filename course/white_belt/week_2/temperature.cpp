#include <iostream>
#include <numeric>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> temperatures(n);

    for (auto &v : temperatures) {
        std::cin >> v;
    }

    double average = static_cast<double>(std::accumulate(begin(temperatures), end(temperatures), 0)) / n;

    size_t counter = 0;
    for (const auto &v: temperatures) {
        if (v > average) {
            ++counter;
        }
    }

    std::cout << counter << std::endl;

    for (size_t i = 0; i < n; ++i) {
        if (temperatures[i] > average) {
            std::cout << i << ' ';
        }
    }
    std::cout << std::endl;

    return 0;
}
