#include <iostream>

int Factorial(int number) {
    int result = 1;

    while (number > 0) {
        result *= number--;
    }

    return result;
}

int main() {
    int n;
    std::cin >> n;

    std::cout << Factorial(n) << std::endl;

    return 0;
}
