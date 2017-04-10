#include <iostream>

using namespace std;

int sum(const int a, const int b) {
    if (b == 0) {
        return a;
    } else if (b < 0) {
        return sum(a, b + 1) - 1;
    } else if (b > 0) {
        return sum(a, b - 1) + 1;
    }
}

int main() {
    int a, b;
    cin >> a >> b;

    cout << sum(a, b);

    return 0;
}
