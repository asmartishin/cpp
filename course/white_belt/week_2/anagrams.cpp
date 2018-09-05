#include <iostream>
#include <map>

using std::string;

std::map<char, int> BuildCharCounters(const string& inputString) {
    std::map<char, int> inputStringCharsCount;

    for (const auto& c : inputString) {
        ++inputStringCharsCount[c];
    }

    return inputStringCharsCount;
}

int main() {
    int n;
    string firstString, secondString;
    std::cin >> n;

    for (size_t i = 0; i < n; ++i) {
        std::cin >> firstString >> secondString;
        std::cout << (BuildCharCounters(firstString) == BuildCharCounters(secondString) ? "YES": "NO") << std::endl;
    }

    return 0;
}
