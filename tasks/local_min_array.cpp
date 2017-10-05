#include <iostream>
#include <vector>

using namespace std;


int local_min(vector<int> &v, int l, int r) {
    int m = (l + r) / 2;

    if (m - 1 > 0 && m + 1 < v.size()) {
        if (v[m - 1] > v[m] && v[m + 1] > v[m])
            return v[m];
        else if (v[m - 1] < v[m])
            return local_min(v, l, m + 1);
        else
            return local_min(v, m, r);
    } else {
        return v[m];
    }
}


int main() {
    int n;

    cin >> n;

    vector<int> v(n);

    for (size_t i = 0; i < n; ++i) {
        cin >> v[i];
    }

    cout << local_min(v, 0, n) << endl;
}
