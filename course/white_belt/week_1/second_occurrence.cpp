#include <iostream>
#include <vector>

int main() {
    std::string inputString;
    std::vector<size_t> occurrences;
    int result;

    std::cin >> inputString;

    for (size_t i = 0; i < inputString.size(); ++i) {
        if (inputString[i] == 'f') {
            occurrences.push_back(i);
        }
    }

    if (occurrences.size() >= 2) {
        result = occurrences[1];
    } else if (occurrences.size() == 1) {
        result = -1;
    } else {
        result = -2;
    }

    std::cout << result << std::endl;

    return 0;
}
