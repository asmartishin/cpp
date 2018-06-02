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

using namespace std;

#define endl '\n'


int main() {
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.precision(10);

    int n;
    string s;
    cin >> n;

    vector<pair<int, string> > strings(n);

    for (size_t i = 0; i < n; ++i) {
        cin >> s;
        strings[i] = make_pair(0, s);
    }

    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < n; ++j) {
            if (strings[i].second.find(strings[j].second) != string::npos) {
                ++strings[i].first;
            }
        }
    }

    sort(strings.begin(), strings.end());

    for (size_t i = 1; i < n; ++i) {
        if (strings[i].second.find(strings[i - 1].second) == string::npos) {
            cout << "NO" << endl;
            return 0;
        }
    }

    cout << "YES" << endl;

    for (const auto &v: strings)
        cout << v.second << endl;

    return 0;
}
