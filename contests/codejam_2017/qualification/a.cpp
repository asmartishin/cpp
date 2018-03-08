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

int solve() {
    string s;
    int k;
    int result = 0;

    cin >> s >> k;

    int n = s.size();
    vector<int> dp(n, 0);

    for (size_t i = 0; i < n - k + 1; ++i) {
        if ((dp[i] % 2 == 0 && s[i] == '-') || (dp[i] % 2 == 1 && s[i] == '+')) {
            ++result;
            for (size_t j = i; j < i + k; ++j) {
                dp[j] += 1;
            }
        }
    }

    for (size_t i = n - k + 1; i < n; ++i) {
        if ((dp[i] % 2 == 0 && s[i] == '-') || (dp[i] % 2 == 1 && s[i] == '+')) {
            return -1;
        }
    }
    return result;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.precision(10);
    int t;

    cin >> t;

    for (size_t i = 0; i < t; ++i) {
        auto result= solve();

        cout << "Case #" << i + 1 << ": ";
        if (result == -1)
            cout << "IMPOSSIBLE";
        else
            cout << result;
        cout << endl;
    }

    return 0;
}
