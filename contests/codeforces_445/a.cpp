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


int sum1(vector<int> &v) {
    return v[0] + v[1] + v[2];
}


int sum2(vector<int> &v) {
    return v[3] + v[4] + v[5];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.precision(10);

    int n = 6;

    vector<int> powers(n);

    for (size_t i = 0; i < n; ++i)
        cin >> powers[i];

    sort(powers.begin(), powers.end());

     do {
        if (sum1(powers) == sum2(powers)) {
            cout << "YES" << endl;
            return 0;
        }
    } while (next_permutation(powers.begin(), powers.end()));

    cout << "NO" << endl;

    return 0;
}
