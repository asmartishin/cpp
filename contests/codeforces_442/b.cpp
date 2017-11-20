#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <limits>
#include <cassert>
#include <numeric>

using namespace std;

#define endl '\n'


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.precision(10);

    string s;
    getline(cin, s);

    int n = s.size();

    vector<int> a(n + 1, 0);
    int m = 0;

    for (size_t i = 1; i <= n; ++i) {
        a[i] = a[i - 1] + (s[i - 1] == 'a');
    }

    for (int i = 0; i <= n; ++i) {
        for (int j = i; j <= n; ++j) {
            m = max(m, j - i + 2 * a[i] - 2 * a[j] + a[n]);
        }
    }

    cout << m << endl;

    return 0;
}
