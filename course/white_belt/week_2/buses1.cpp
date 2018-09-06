#include <iostream>
#include <string>
#include <map>
#include <vector>

using std::vector;
using std::string;

int main() {
    int q, stopCount;
    string command, bus, stop;

    std::map<string, vector<string>> busToStops;
    std::map<string, vector<string>> stopToBuses;

    std::cin >> q;
    for (size_t i = 0; i < q; ++i) {
        std::cin >> command;
        if (command == "NEW_BUS") {
            std::cin >> bus >> stopCount;
            for (size_t j = 0; j < stopCount; ++j) {
                std::cin >> stop;
                busToStops[bus].push_back(stop);
                stopToBuses[stop].push_back(bus);
            }
        } else if (command == "BUSES_FOR_STOP") {
            std::cin >> stop;

            if (stopToBuses.find(stop) != stopToBuses.end()) {
                for (const auto& b: stopToBuses[stop]) {
                    std::cout << b << ' ';
                }
                std::cout << std::endl;
            } else {
                std::cout << "No stop" << std::endl;
            }
        } else if (command == "STOPS_FOR_BUS") {
            std::cin >> bus;
            if (busToStops.find(bus) == busToStops.end()) {
                std::cout << "No bus" << std::endl;
            } else {
                for (const auto& s: busToStops[bus]) {
                    std::cout << "Stop " << s << ": ";
                    if (stopToBuses[s].size() == 1) {
                        std::cout << "no interchange" << std::endl;
                    } else {
                        for (const auto& b: stopToBuses[s]) {
                            if (b != bus) {
                                std::cout << b << ' ';
                            }
                        }
                        std::cout << std::endl;
                    }
                }
            }
        } else if (command == "ALL_BUSES") {
            if (busToStops.empty()) {
                std::cout << "No buses" << std::endl;
            } else {
                for (const auto& bs: busToStops) {
                    std::cout << "Bus " << bs.first << ": ";
                    for (const auto& s: bs.second) {
                        std::cout << s << ' ';
                    }
                    std::cout << std::endl;
                }
            }
        }
    }

    return 0;
}
