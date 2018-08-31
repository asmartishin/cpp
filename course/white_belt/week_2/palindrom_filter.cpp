#include <iostream>
#include <vector>
#include <sstream>

bool IsPalindrom(const std::string& s) {
    auto l = s.begin();
    auto r = s.end() - 1;

    while (l < r) {
        if (*l++ != *r--) {
            return false;
        }
    }

    return true;
}

std::vector<std::string> PalindromFilter(std::vector<std::string>& words, int minLength) {
    std::vector<std::string> filteredPalindromes;
    for (const auto& palindrome: words) {
        if (palindrome.length() >= minLength && IsPalindrom(palindrome)) {
            filteredPalindromes.push_back(palindrome);
        }
    }

    return filteredPalindromes;
}

int main() {
    int n, minLength;
    std::string s;

    std::cin >> n >> minLength;

    std::vector<std::string> palindromes(n);

    for (size_t i = 0; i < n; ++i) {
        std::cin >> palindromes[i];

    }

    for (const auto& palindrome: PalindromFilter(palindromes, n)) {
        std::cout << palindrome << ' ';
    }

    std::cout << std::endl;

    return 0;
}
