#include <iostream>
#include <set>

int main() {
    size_t n;
    std::string s;
    std::cin >> n;
    std::set<std::string> strings;

    for (size_t i = 0; i < n; ++i) {
        std::cin >> s;
        strings.insert(s);
    }

    std::cout << strings.size() << std::endl;

    return 0;
}
