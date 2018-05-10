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

int maxPowerOf3(long long number) {
    int result = 0;

    while (number % 3 == 0) {
        ++result;
        number /= 3;
    }

    return result;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.precision(10);

    int n;
    long long v;
    cin >> n;

    vector<pair<int, long long> > a;

    for (size_t i = 0; i < n; ++i) {
        cin >> v;
        a.push_back(make_pair(-maxPowerOf3(v), v));
    }

    sort(a.begin(), a.end());

    for (const auto &v: a)
        cout << v.second << ' ';
    cout << endl;

    return 0;
}
