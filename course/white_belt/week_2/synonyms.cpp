#include <iostream>
#include <map>
#include <set>

int main() {
    size_t q;
    std::string command, firstWord, secondWord;
    std::map<std::string, std::set<std::string>> synonyms;
    std::cin >> q;

    for (size_t i = 0; i < q; ++i) {
        std::cin >> command;

        if (command == "ADD") {
            std::cin >> firstWord >> secondWord;
            synonyms[firstWord].insert(secondWord);
            synonyms[secondWord].insert(firstWord);
        } else if (command == "COUNT") {
            std::cin >> firstWord;
            std::cout << synonyms[firstWord].size() << std::endl;
        } else {
            std::cin >> firstWord >> secondWord;
            if (synonyms[firstWord].find(secondWord) != synonyms[firstWord].end()) {
                std::cout << "YES" << std::endl;
            } else {
                std::cout << "NO" << std::endl;
            }
        }
    }

    return 0;
}
