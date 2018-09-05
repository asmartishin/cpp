#include <iostream>
#include <map>

int main() {
    int n;
    std::string command, country, newCapital, oldCountry, newCountry;
    std::map<std::string, std::string> countries;

    std::cin >> n;

    for (size_t i = 0; i < n; ++i) {
        std::cin >> command;

        if (command == "CHANGE_CAPITAL") {
            std::cin >> country >> newCapital;

            if (countries.find(country) == countries.end()) {
                std::cout << "Introduce new country " << country << " with capital " << newCapital << std::endl;
                countries[country] = newCapital;
            } else if (countries[country] == newCapital) {
                std::cout << "Country " << country << " hasn't changed its capital" << std::endl;
            } else {
                std::cout << "Country " << country << " has changed its capital from " << countries[country]
                    << " to " << newCapital << std::endl;
                countries[country] = newCapital;
            }
        } else if (command == "RENAME") {
            std::cin >> oldCountry >> newCountry;

            if (oldCountry == newCountry || countries.find(oldCountry) == countries.end()
                    || countries.find(newCountry) != countries.end()) {
                std::cout << "Incorrect rename, skip" << std::endl;
            } else {
                std::cout << "Country " << oldCountry << " with capital " << countries[oldCountry]
                    << " has been renamed to " << newCountry << std::endl;
                countries[newCountry] = countries[oldCountry];
                countries.erase(oldCountry);
            }
        } else if (command == "ABOUT") {
            std::cin >> country;

            if (countries.find(country) == countries.end()) {
                std::cout << "Country " << country << " doesn't exist" << std::endl;
            } else {
                std::cout << "Country " << country << " has capital " << countries[country] << std::endl;
            }
        } else {
            if (countries.empty()) {
                std::cout << "There are no countries in the world" << std::endl;
            } else {
                for (const auto& country : countries) {
                    std::cout << country.first << "/" << country.second << " ";
                }
                std::cout << std::endl;
            }
        }
    }

    return 0;
}
