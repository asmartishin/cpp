#include <iostream>
#include <map>
#include <set>

std::set<std::string> BuildMapValuesSet(const std::map<int, std::string>& m) {
    std::set<std::string> values;
    for (const auto& kv: m) {
        values.insert(kv.second);
    }

    return values;
}

int main() {
    std::map<int, std::string> m{
        {1, "odd"},
        {2, "even"},
        {3, "odd"}
    };

    auto s = BuildMapValuesSet(m);

    for (const auto& v: s) {
        std::cout << v << ' ';
    }

    std::cout << std::endl;
    return 0;
}
