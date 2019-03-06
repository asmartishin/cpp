#include <iostream>
#include <fstream>


int main() {
    std::ifstream input("input.txt");
    std::string line;

    std::ofstream output("output.txt");

    while (getline(input, line)) {
        output << line << std::endl;
    }

    return 0;
}
