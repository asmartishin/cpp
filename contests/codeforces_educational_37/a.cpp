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

    int t, n, k, v;

    cin >> t;

    for (size_t i = 0; i < t; ++i) {
        cin >> n >> k;

        unordered_set<int> garden;
        queue<int> q;
        int result = 1;

        for (size_t j = 0; j < k; ++j) {
            cin >> v;
            --v;
            garden.insert(v);
        }

        while (garden.size() != n) {
            ++result;

            for (auto const &v: garden) {
                if (v - 1 >= 0)
                    q.push(v - 1);
                if (v + 1 < n)
                    q.push(v + 1);
            }

            while (!q.empty()) {
                garden.insert(q.front());
                q.pop();
            }
        }

        cout << result << endl;
    }

    return 0;
}
