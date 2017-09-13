#include <iostream>
#include <algorithm>

using namespace std;


int main() {
    int c, v0, v1, a, l, np, p = 0, d = 0;
    cin >> c >> v0 >> v1 >> a >> l;

    while (true) {
        ++d;
        if (d > 1) {
            np = v0 + a * (d - 1);
        } else {
            np = v0;
        }
        p += min(np, v1);
        if (p >= c) {
            break;
        }
        p -= l;
    }

    cout << d << endl;
    return 0;
}
