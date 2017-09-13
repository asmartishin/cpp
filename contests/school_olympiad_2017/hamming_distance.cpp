#include <iostream>


int main() {
    std::string l;
    std::string r;

    std::cin >> l >> r;

    int lengthL = l.length();
    int lengthR = r.length();

    int result = 0;

    if (lengthL > lengthR) {
        result = lengthL;
    } else if (lengthL < lengthR) {
        result = lengthR;
    } else {
        int i = 0;
        for (std::string::iterator it = l.begin(); it != l.end(); ++it) {
            if (r[i] != l[i]) {
                result = lengthR - i;
                break;
            }
            i++;
        }
    }

    std::cout << result << std::endl;

    return 0;
}
