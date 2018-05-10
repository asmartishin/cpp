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
#include <limits>
#include <cassert>
#include <fstream>
#include <array>

using namespace std;

#define endl '\n'


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.precision(10);

    int n, subLength = 0, subLast = 0;
    cin >> n;

    vector<int> numbers(n);
    vector<int> subset;
    map<int, int> dp;

    for (size_t i = 0; i < n; ++i)
        cin >> numbers[i];

    for (size_t i = 0; i < n; ++i) {
        dp[numbers[i]] = dp[numbers[i] - 1] + 1;
        if (dp[numbers[i]] > subLength) {
            subLength = dp[numbers[i]];
            subLast = numbers[i];
        }
    }

    for (int i = n - 1; i >= 0; --i) {
        if (numbers[i] == subLast) {
            subset.push_back(i + 1);
            --subLast;
        }
    }

    reverse(subset.begin(), subset.end());

    cout << subset.size() << endl;
    for (const auto &v: subset)
        cout << v << ' ';
    cout << endl;

    return 0;
}
