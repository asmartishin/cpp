#include <iostream>
#include <vector>

using namespace std;


int partition(vector<int> &v, int l, int r) {
    int m = v[(l + r) / 2];

    while (l <= r) {
        while (v[l] < m) {
            ++l;
        }
        while (v[r] > m) {
            --r;
        }
        if (l <= r) {
            swap(v[l++], v[r++]);
        }
    }
    return r;
}


int quickSelect(vector<int> &v, int k) {
    int l = 0;
    int r = v.size() - 1;

    while (l <= r) {
        int m = partition(v, l, r);

        if (m == k) {
            return v[m];
        } else if (k < m) {
            r = m;
        } else {
            k -= m + 1;
            l = m + 1;
        }
    }

    return -1;
}


int main() {
    int n, k;

    cin >> n >> k;

    vector<int> v(n);

    for (size_t i = 0; i < n; ++i) {
       cin >> v[i];
    }

    cout << quickSelect(v, k) << endl;
    return 0;
}
