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

    int m;
    cin >> m;
    vector<int> v(m);
    vector<int> result;

    for (size_t i = 0; i < m; ++i)
        cin >> v[i];

    int min_element = v[0];

    for (auto const &i: v) {
        if (i % min_element != 0) {
            cout << -1 << endl;
            return 0;
        }
    }

    for (size_t i = 0; i < m; ++i) {
        result.push_back(min_element);
        result.push_back(v[i]);
    }

    cout << result.size() << endl;
    for (auto const &i: result)
        cout << i << ' ';
    cout << endl;

    return 0;
}
