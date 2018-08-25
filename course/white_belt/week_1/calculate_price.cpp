#include <iostream>
#include <algorithm>

int main() {
    double n, a, b, x, y;
    std::cin >> n >> a >> b >> x >> y;

    if (n > b) {
        n *= ((100 - y) / 100);
    } else if (n > a) {
        n *= ((100 - x) / 100);
    }

    std::cout << n << std::endl;
}
