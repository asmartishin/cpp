#include <iostream>

int main() {
    std::string s1, s2, s3;
    std::cin >> s1 >> s2 >> s3;

    if (s1 <= s2 && s1 <= s3) {
        std::cout << s1 << std::endl;
    } else if (s2 <= s1 && s2 <= s3) {
        std::cout << s2 << std::endl;
    } else {
        std::cout << s3 << std::endl;
    }

    return 0;
}
