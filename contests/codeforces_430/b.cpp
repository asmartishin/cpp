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

bool pointInCircle(int x1, int y1, double r, int x2, int y2, bool v) {
//    if (v) {
//        cout << r << endl;
//        cout << pow((x2 - x1), 2) << endl;
//        cout << pow((y2 - y1), 2) << endl;
//        cout << pow(r, 2) << endl;
//        cout << endl;
//    }
    if (pow((x2 - x1), 2) + pow((y2 - y1), 2) <= pow(r, 2))
        return true;
    return false;
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.precision(10);

    int n, x, y, r, d, rp, result = 0;

    cin >> r >> d >> n;

    for (size_t i = 0; i < n; ++i) {
        cin >> x >> y >> rp;

	if (pow(x, 2) + pow(y, 2) <= pow(r - rp, 2) && 2 * rp <= d && pow(x, 2) + pow(y, 2) >= pow(r - d + rp, 2)) {
            ++result;
        }
    }

    cout << result << endl;

    return 0;
}
