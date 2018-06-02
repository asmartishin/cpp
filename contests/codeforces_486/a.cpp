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

    int n, k, rating;
    unordered_map<int, vector<int> > ratings;

    cin >> n >> k;
    vector<int> a(n);

    for (size_t i = 0; i  < n; ++i) {
        cin >> rating;
        ratings[rating].push_back(i);
    }

    if (ratings.size() >= k) {
        cout << "YES" << endl;
        size_t i = 0;
        for (const auto &v: ratings) {
            if (++i > k)
                break;
            cout << v.second.front() + 1 << ' ';
        }
        cout << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
