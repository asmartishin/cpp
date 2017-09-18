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


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.precision(10);

    int l, r, x, y;
    double b, k;
    bool result = false;

    cin >> l >> r >> x >> y >> k;

    for (size_t a = l; a <= r; ++a) {
        b = a / k;
        if (floor(b) == b && x <= b && b <= y) {
            result = true;
        }
    }

    if (result) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
