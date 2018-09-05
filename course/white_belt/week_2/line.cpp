#include <iostream>
#include <string>
#include <vector>
#include <cmath>

int main() {
    int n, value;
    std::string command;
    std::vector<bool> people;
    std::size_t worringPeopleCount = 0;

    std::cin >> n;

    for (std::size_t i = 0; i < n; ++i) {
        std::cin >> command;

        if (command == "WORRY") {
            std::cin >> value;
            if (!people[value]) {
                people[value] = true;
                ++worringPeopleCount;
            }
        } else if (command == "QUIET") {
            std::cin >> value;
            if (people[value]) {
                people[value] = false;
                --worringPeopleCount;
            }
        } else if (command == "COME") {
            std::cin >> value;
            if (value > 0) {
                people.resize(people.size() + value, false);
            } else {
                for (std::size_t i = 0; i < std::abs(value); ++i) {
                    if (people.back()) {
                        --worringPeopleCount;
                    }
                    people.pop_back();
                }
            }
        } else {
            std::cout << worringPeopleCount << std::endl;
        }
    }

    return 0;
}
