#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int number;
    std::cin >> number;
    std::vector<bool> bits;

    while (number) {
        bits.push_back(number % 2);
        number /= 2;
    }

    std::reverse(std::begin(bits), std::end(bits));

    for (const auto& v: bits) {
        std::cout << v;
    }

    std::cout << std::endl;

    return 0;
}
