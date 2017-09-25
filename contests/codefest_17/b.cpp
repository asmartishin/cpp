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

using namespace std;

#define endl '\n'


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.precision(10);

    int n;
    long long p, q, r, a;

    cin >> n >> p >> q >> r;

    vector<vector<long long> > states(n, vector<long long>(3));

    cin >> a;

    states[0][0] = p * a;
    states[0][1] = p * a + q * a;
    states[0][2] = p * a + q * a + r * a;

    for (size_t i = 1; i < n; ++i) {
        cin >> a;
        states[i][0] = max(states[i - 1][0], p * a);
        states[i][1] = max(states[i - 1][1], states[i][0] + q * a);
        states[i][2] = max(states[i - 1][2], states[i][1] + r * a);
    }

    cout << states[n - 1][2] << endl;

    return 0;
}
