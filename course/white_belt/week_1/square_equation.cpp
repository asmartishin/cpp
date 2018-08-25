#include <iostream>
#include <cmath>

int main() {
    double a, b, c;
    std::cin >> a >> b >> c;

    auto discriminant = std::sqrt(b * b - 4 * a * c);

    if (a == 0) {
        if (b != 0) {
            std::cout << -c / b << std::endl;
        }
    } else if (discriminant == 0) {
        std::cout << -b / (2 * a);
    } else if (discriminant > 0) {
        auto x1 = (-b + discriminant) / (2 * a);
        auto x2 = (-b - discriminant) / (2 * a);

        std::cout << x1 << ' ' << x2 << std::endl;
    }

    return 0;
}
