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

    int n, m, k, result = 0;
    cin >> n >> m >> k;
    queue<int> alarms_indices;

    vector<int> alarms(n);

    for (size_t i = 0; i < n; ++i) {
        cin >> alarms[i];
    }

    sort(alarms.begin(), alarms.end());

    for (size_t i = 0; i < alarms.size(); ++i) {
        while (!alarms_indices.empty()) {
            if (alarms[i] - alarms_indices.front() >= m)
                alarms_indices.pop();
            else
                break;
        }

        if (alarms_indices.size() < k - 1)
            alarms_indices.push(alarms[i]);
        else
            ++result;
    }

    cout << result;

    return 0;
}
