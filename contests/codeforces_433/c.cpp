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

using namespace std;

#define endl '\n'


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.precision(10);

    int n, k, c;

    vector<pair<int, int> > v;
    set<pair<long long, int> > s;

    cin >> n >> k;
    int t = k;

    vector<int> result(n);
    long long delay = 0;

    for (size_t i = 0; i < k; ++i) {
        cin >> c;
        s.insert(make_pair(c, i));
    }

    for (size_t i = k; i < n + k; ++i) {
        if (i < n) {
            cin >> c;
            s.insert(make_pair(c, i));
        }
        delay += s.rbegin()->first * (t - s.rbegin()->second);
        result[s.rbegin()->second] = t + 1;
        ++t;
        s.erase(*s.rbegin());
    }

//    sort(v.begin(), v.end(), [](const pair<int, int> &left, const pair<int, int> &right) {
//        return left.second > right.second;
//    });
//
//    while (!v.empty()) {
//        for (size_t i = 0; i < v.size(); ++i) {
//            if (v[i].first <= k) {
//                delay += (k - v[i].first) * v[i].second;
//                result[v[i].first] = k + 1;
//                v.erase(v.begin() + i);
//                ++k;
//                break;
//            }
//        }
//    }
//
    cout << delay << endl;

    for (size_t i = 0; i < result.size(); ++i) {
        cout << result[i] << ' ';
    }

    cout << endl;


    return 0;
}
