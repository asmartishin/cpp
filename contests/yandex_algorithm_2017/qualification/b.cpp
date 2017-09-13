#include <iostream>

using namespace std;


int main() {
    long long a, b, c, d;
    cin >> a >> b >> c >> d;
    if (a + b == c + d || a + c == b + d || a + d == b + c) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}
