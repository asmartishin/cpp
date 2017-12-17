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
#include <climits>
#include <cassert>

using namespace std;

#define endl '\n'


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.precision(10);

    int n, a, b;

    cin >> n >> a >> b;

    int x = 0;

    while (x * a <= n) {
        if ((n - x * a) % b == 0) {
            cout << "YES" << endl;
            cout << x << ' ' << (n - x * a) / b << endl;
            return 0;
        }
        ++x;
    }

    cout << "NO" << endl;

    return 0;
}
