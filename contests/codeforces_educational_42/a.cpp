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
#include <fstream>
#include <array>

using namespace std;

#define endl '\n'


size_t lower_bound(vector<int> &a, int v) {
    size_t l = 0;
    size_t r = a.size();

    while (l < r) {
        size_t m = (l + r) / 2;

        if (v <= a[m])
            r = m;
        else
            l = m + 1;
    }

    return l;
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.precision(10);

    int n, v;

    cin >> n;

    vector<int> a(n + 1, 0);

    for (size_t i = 1; i <= n; ++i) {
        cin >> v;
        a[i] = a[i - 1] + v;
    }

    v = ceil((double)a[n] / 2);

    cout << lower_bound(a, v) << endl;

    return 0;
}
