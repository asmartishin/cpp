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

    int n, result = INT_MAX;

    cin >> n;

    n *= 2;

    vector<int> w(n);

    for (size_t i = 0; i < n; ++i) {
        cin >> w[i];
    }

    sort(w.begin(), w.end());

    for (size_t i = 0; i < w.size(); ++i) {
        for (size_t j = i + 1; j < w.size(); ++j) {
            int sum = 0;
            int wp = 0;
            for (size_t k = 0; k < n; ++k) {
                if (k != i && k != j) {
                    if (!wp) {
                        wp = w[k];
                    } else {
                        sum += w[k] - wp;
                        wp = 0;
                    }
                }
            }
            result = min(sum, result);
        }
    }

    cout << result << endl;

    return 0;
}
