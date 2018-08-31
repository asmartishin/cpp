#include <iostream>

void UpdateIfGreater(const int& a, int& b) {
    if (a > b) {
        b = a;
    }
}

int main() {
    int a, b;
    std::cin >> a >> b;

    UpdateIfGreater(a, b);

    std::cout << a << ' ' << b << std::endl;

    return 0;
}
