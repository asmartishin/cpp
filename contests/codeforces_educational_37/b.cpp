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

    int t;

    cin >> t;

    for (size_t i = 0; i < t; ++i) {
        int n, l, r, s = 1, result;

        cin >> n;

        for (size_t i = 0; i < n; ++i) {
            cin >> l >> r;

            if (l >= s || r >= s) {
                if (l > s)
                    s = l;

                result = s;
                ++s;
            } else
                result = 0;

            cout << result << ' ';
        }
        cout << endl;
    }

    return 0;
}
