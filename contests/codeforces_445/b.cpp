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

    unordered_map<int, int> visits;
    int n, cn;
    pair<int, int> last_visit = make_pair(-1, numeric_limits<int>::max());

    cin >> n;

    for (size_t i = 0; i < n; ++i) {
        cin >> cn;
        visits[cn] = i;
    }

    for (auto const &v: visits) {
        if (v.second < last_visit.second) {
            last_visit.first = v.first;
            last_visit.second = v.second;
        }
    }

    cout << last_visit.first << endl;

    return 0;
}
