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
#include <climits>
#include <cassert>
#include <numeric>

using namespace std;

#define endl '\n'


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.precision(10);

    int n, k, x;

    cin >> n >> k >> x;

    vector<int> v(n);

    for (size_t i = 0; i < n; ++i)
        cin >> v[i];

    for (size_t i = v.size() - k; i <= v.size() - 1; ++i) {
        v[i] = x;
    }

    cout << accumulate(v.begin(), v.end(), 0) << endl;

    return 0;
}
