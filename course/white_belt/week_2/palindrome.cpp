#include <iostream>

bool IsPalindrom(std::string& s) {
    auto l = s.begin();
    auto r = s.end() - 1;

    while (l < r) {
        if (*l++ != *r--) {
            return false;
        }
    }

    return true;
}

int main() {
    std::string s;
    std::cin >> s;

    std::cout << IsPalindrom(s) << std::endl;

    return 0;
}
