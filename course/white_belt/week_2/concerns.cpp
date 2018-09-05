#include <iostream>
#include <vector>

int main() {
    int n, day;
    std::string command, task;
    std::vector<uint8_t> monthsToDays {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    std::vector<std::vector<std::string>> tasks(31);
    size_t currentMonth = 0;

    std::cin >> n;

    for (size_t i = 0; i < n; ++i) {
        std::cin >> command;

        if (command == "ADD") {
            std::cin >> day >> task;
            tasks[day - 1].push_back(task);
        } else if (command == "NEXT") {
            currentMonth = (currentMonth + 1) % 12;

            uint8_t nextMontDays = monthsToDays[currentMonth];

            if (nextMontDays < tasks.size()) {
                for (size_t j = nextMontDays; j < tasks.size(); ++j) {
                    tasks[nextMontDays - 1].insert(end(tasks[nextMontDays - 1]), begin(tasks[j]), end(tasks[j]));
                }
            }

            tasks.resize(nextMontDays);
        } else {
            std::cin >> day;

            std::cout << tasks[day - 1].size() << ' ';

            for (auto const& task: tasks[day - 1]) {
                std::cout << task  << ' ';
            }

            std::cout << std::endl;
        }
    }

    return 0;
}

