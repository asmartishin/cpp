#include <iostream>
#include <vector>
#include <string>
#include <algorithm>


int main() {
    std::size_t n;
    std::cin >> n;
    std::vector<std::string> v(n);

    for (auto &i: v) {
        std::cin >> i;
    }

    std::sort(std::begin(v), std::end(v), [](const std::string& lhs, const std::string& rhs) {
        return std::lexicographical_compare(
            std::begin(lhs), std::end(lhs), std::begin(rhs), std::end(lhs), [](char l, char r) {
                return std::tolower(l) < std::tolower(r);
            }
        );
    });

    for (const auto& i: v) {
        std::cout << i << ' ';
    }

    std::cout << std::endl;

    return 0;
}
