#include <iostream>
#include <fstream>
#include <iomanip>

int main() {
    std::ifstream input("input.txt");
    double number;

    std::cout << std::fixed <<  std::setprecision(3);

    while (input >> number) {
        std::cout << number << std::endl;
    }

    return 0;
}
