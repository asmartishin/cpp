#include <iostream>
#include <vector>

using namespace std;


int local_min(vector<int> &v) {
    int l = 0, r = v.size();

    if (v[l] <= v[l + 1])
        return v[l];
    else if (v[r - 2] >= v[r - 1])
        return v[r];
    else {
        while (l < r) {
            int m = (l + r) / 2;
            if (v[m - 1] >= v[m] && v[m + 1] >= v[m])
                return v[m];
            else if (v[m - 1] <= v[m])
                r = m + 1;
            else
                l = m;
        }
    }

    return -1;
}


int main() {
    int n;

    cin >> n;

    vector<int> v(n);

    for (size_t i = 0; i < n; ++i) {
        cin >> v[i];
    }

    cout << local_min(v) << endl;
}
