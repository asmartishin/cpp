#include <iostream>
#include <vector>

using namespace std;


int partition(vector<int> &v, int l, int r) {
    int m = l;
    for (size_t i = l + 1; i <= r; ++i) {
        if (v[i] <= v[l]) {
            ++m;
            swap(v[i], v[m]);
        }
    }
    swap(v[l], v[m]);
    return m;
}


pair<int, int> partition3(vector<int> &v, int l, int r) {
    int ml = l + 1;
    int mr = l;

    for (size_t i = ml; i <= r; ++i) {
        if (v[i] <= v[l]) {
            ++mr;
            swap(v[i], v[mr]);
            if (v[mr] < v[l]) {
                swap(v[ml], v[mr]);
                ++ml;
            }
        }
    }
    swap(v[l], v[ml - 1]);
    return make_pair(ml, mr);
}


void quickSort(vector<int> &v, int l, int r) {
    if (l >= r) {
        return;
    }

    int k = l + rand() % (r - l + 1);
    swap(v[l], v[k]);

    pair<int, int> m = partition3(v, l, r);

    quickSort(v, l, m.first - 1);
    quickSort(v, m.second + 1, r);
}


int main() {
    int n;

    cin >> n;

    vector<int> v(n);

    for (size_t i = 0; i < n; ++i) {
        cin >> v[i];
    }

    quickSort(v, 0, n - 1);

    for (size_t i = 0; i < n; ++i) {
        cout << v[i] << ' ';
    }
    cout << endl;

    return 0;
}
