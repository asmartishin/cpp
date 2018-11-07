#include <iostream>
#include <map>
#include <vector>

int main() {
    size_t q, n;
    std::size_t currentLine = 0;
    std::map<std::vector<std::string>, std::size_t> stopsToLines;

    std::cin >> q;

    for (size_t i = 0; i < q; ++i) {
        std::cin >> n;
        std::vector<std::string> stops(n);
        for (auto& s: stops) {
            std::cin >> s;
        }

        if (stopsToLines.find(stops) == stopsToLines.end()) {
            ++currentLine;
            std::cout << "New bus " << currentLine << std::endl;
            stopsToLines[stops] = currentLine;
        } else {
            std::cout << "Already exists for " << stopsToLines[stops] << std::endl;
        }
    }

    return 0;
}
