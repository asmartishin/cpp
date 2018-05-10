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


int partition(vector<int> &v, int l, int r, int pivot) {
    swap(v[pivot], v[l]);
    int p = l;

    for (size_t i = l + 1; i < r; ++i) {
        if (v[i] <= v[l]) {
            ++p;
            swap(v[i], v[p]);
        }
    }

    swap(v[l], v[p]);

    return p;
}


int quickSelect(vector<int> &v, int l, int r, int k) {
    if (l < r) {
        int pivot = (l + r) / 2;
        int p = partition(v, l, r, pivot);

        if (p == k)
            return v[k];
        else if (k < p)
            return quickSelect(v, l, p, k);
        else
            return quickSelect(v, p + 1, r, k);
    } else
        return v[l];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.precision(10);

    int n, k;

    cin >> n >> k;

    vector<int> a(n);

    for (size_t i = 0; i < n; ++i) {
        cin >> a[i];
    }

    if (k == 0 && find(a.begin(), a.end(), 1) == a.end()) {
        cout << 1 << endl;
    } else {
        auto result = quickSelect(a, 0, a.size(), k - 1);
        cout << (result != a[k] ? result : -1) << endl;
    }

    return 0;
}
