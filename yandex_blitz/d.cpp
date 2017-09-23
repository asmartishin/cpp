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

    int n, m;

    cin >> n;

    vector<int> a(n);
    vector<bool> states(1e4 + 1, false);
    states[0] = true;

    for (size_t i = 0; i < n; ++i) {
        cin >> a[i];
    }

    cin >> m;

    sort(a.begin(), a.end());

    m -= a.back();
    a.pop_back();

    if (m >= 0) {
        for (size_t i = 0; i < a.size(); ++i) {
            for (int j = states.size() - 1; j >= 0; --j) {
                if (states[j] == true) {
                    if (j + a[i] < states.size()) {
                        states[j + a[i]] = true;
                    }
                }
            }
        }

        if (states[m] == true) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    } else {
        cout << "No" << endl;
    }

    return 0;
}
