#include <iostream>

using std::cout;
using std::cin;

long long gcd(long long a, long long b) {
    while (b) {
        a %= b;
        a += b;
        b = a - b;
        a -= b;
    }
    return a;
}

int main() {
    long long a;
    long long b;
    cin >> a;
    cin >> b;
    cout << gcd(a, b) << "\n";
    return 0;
}
