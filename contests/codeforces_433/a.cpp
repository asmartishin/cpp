#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>

using namespace std;

#define endl '\n'

int gcd(int a, int b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.precision(10);

    int n, a, b, a_max, b_max;
    double old_max = 0, new_max;

    cin >> n;

    for (a = 1; a < n / 2 + 1; ++a) {
        b = n - a;
        if (gcd(a, b) == 1) {
            new_max = (double)a / b;
            if (new_max > old_max) {
                old_max = new_max;
                a_max = a;
                b_max = b;
            }
        }
    }

    cout << a_max << ' ' << b_max << endl;

    return 0;
}
