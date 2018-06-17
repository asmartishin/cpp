#include <iostream>

using namespace std;


int main() {
    int x = 3, y = 5;

    while (y != 0) {
        int carry = x & y;
        x = x ^ y;
        y = carry << 1;
    }

    cout << x << endl;

    return 0;
}
