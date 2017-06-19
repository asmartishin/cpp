#include <iostream>

using namespace std;

bool check_palindrome(int a, int b) {
    return (a == ((b % 10) * 10) + (b / 10));
}

int main() {
    int a, b;
    char c;
    int result = 0;

    cin >> a >> c >> b;

    while (!check_palindrome(a, b)) {
        if (b < 59) {
            ++b;
        } else {
            b = 0;
            if (a < 23) {
                ++a;
            } else {
                a = 0;
            }
        }
        ++result;
    }

    cout << result << endl;

    return 0;
}
