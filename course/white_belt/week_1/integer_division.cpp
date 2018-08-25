#include <iostream>

int main() {
    int firstNumber, secondNumber;
    std::string result;

    std::cin >> firstNumber >> secondNumber;

    if (secondNumber == 0) {
        result = "Impossible";
    } else {
        result = std::to_string(firstNumber / secondNumber);
    }

    std::cout << result << std::endl;

    return 0;
}
