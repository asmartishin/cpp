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

    unordered_set<int> visits;

    visits.insert(0);

    int n, t;
    cin >> n;

    for (size_t i = 1; i <= n; ++i) {
        cin >> t;

        if (visits.find(t) != visits.end()) {
            visits.erase(t);
            visits.insert(i);
        } else {
            visits.insert(i);
        }
    }

    cout << visits.size() << endl;

    return 0;
}
