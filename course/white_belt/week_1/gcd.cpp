#include <iostream>

int main() {
    int firstNumber, secondNumber;
    std::cin >> firstNumber >> secondNumber;

    while (secondNumber) {
        firstNumber %= secondNumber;
        std::swap(firstNumber, secondNumber);
    }

    std::cout << firstNumber << std::endl;

    return 0;
}
