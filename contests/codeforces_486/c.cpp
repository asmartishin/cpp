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
#include <numeric>

using namespace std;

#define endl '\n'


int main() {
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.precision(10);

    int k;
    int n;

    cin >> k;

    unordered_map<int, vector<pair<int, int> > > sums;

    for (size_t i = 0; i < k; ++i) {
        cin >> n;
        vector<int> vec(n);
        unordered_set<int> usedSums;

        for (size_t j = 0; j < n; ++j) {
            cin >> vec[j];
        }

        int sum = accumulate(vec.begin(), vec.end(), 0);

        for (size_t j = 0; j < n; ++j) {
            int sumWithouElement = sum - vec[j];
            if (usedSums.find(sumWithouElement) == usedSums.end()) {
                sums[sumWithouElement].push_back(make_pair(i, j));
                usedSums.insert(sumWithouElement);
            }
        }
    }

    for (auto const &v: sums) {
        if (v.second.size() >= 2) {
            cout << "YES" << endl;
            cout << v.second[0].first + 1 << ' ' << v.second[0].second + 1 << endl;
            cout << v.second[1].first + 1 << ' ' << v.second[1].second + 1 << endl;
            return 0;
        }
    }

    cout << "NO" << endl;

    return 0;
}
