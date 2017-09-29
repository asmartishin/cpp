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

    int n, a;
    map<int, int> m;

    cin >> n;

    for (size_t i = 0; i < n; ++i) {
        cin >> a;
        ++m[a];
    }

    if (m.size() == 2 && m.begin()->second == m.rbegin()->second) {
        cout << "YES" << endl;
        cout << m.begin()->first << ' ' << m.rbegin()->first << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
