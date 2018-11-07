#include <iostream>
#include <map>
#include <set>

int main() {
    size_t q, n;
    std::size_t currentLine = 0;
    std::map<std::set<std::string>, std::size_t> stopsToLines;
    std::string stop;

    std::cin >> q;

    for (size_t i = 0; i < q; ++i) {
        std::cin >> n;
        std::set<std::string> stops;
        for (size_t i = 0; i < n; ++i) {
            std::cin >> stop;
            stops.insert(stop);
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
