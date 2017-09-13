#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;


int main() {
    int n, a;
    double mind, ca, fa, sa, ta, p;
    bool mswap = false;
    vector<int> result(3);
    cin >> n >> a;

    ca = (double)180 * (n - 2) / n;
    ta = (double)(180 - ca) / 2;
    p = 180 - ta;

    mind = abs(ca - a);

    result[0] = 1;
    result[1] = 2;
    result[2] = 3;

    for (size_t i = 3; i < n / 2 + 3; ++i) {
        fa = ta * (i - 2);
        sa = p - fa;

        if (abs(sa - a) < mind) {
            mind = abs(sa - a);
            mswap = false;
            result[2] = i;
        }

        if (abs(fa - a) < mind) {
            mind = abs(fa - a);
            mswap = true;
            result[2] = i;
        }
    }

    if (mswap) {
        swap(result[0], result[1]);
    }

    for (size_t i = 0; i < 3; ++i) {
        cout << result[i] << ' ';
    }
    cout << endl;

    return 0;
}
