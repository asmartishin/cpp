#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;


int partition2(vector<int> &v, int l, int r) {
    int x = v[l];
    int y = l;
    for (int i = l + 1; i <= r; i++) {
        if (v[i] <= x) {
            y++;
            swap(v[i], v[y]);
        }
    }
    swap(v[l], v[y]);

    return y;
}


pair<int, int> partition3(vector<int> &v, int l, int r) {
    int x = v[l];
    int y = l + 1;
    int z = l;
    for (int i = l + 1; i <= r; i++) {
        if (v[i] <= x) {
            z++;
            swap(v[i], v[z]);
            if (v[z] < x) {
                swap(v[y], v[z]);
                y++;
            }
        }
    }
    swap(v[l], v[y - 1]);
    return make_pair(y, z);
}


void quickSortRandomized(vector<int> &v, int l, int r) {
    if (l >= r) {
        return;
    }

    int k = l + rand() % (r - l + 1);
    swap(v[l], v[k]);

    pair<int, int> m = partition3(v, l, r);

    quickSortRandomized(v, l, m.first - 1);
    quickSortRandomized(v, m.second + 1, r);
}


int main() {
    int n;
    cin >> n;

    vector<int> v(n);

    for (size_t i = 0; i < n; ++i) {
        cin >> v[i];
    }

    quickSortRandomized(v, 0, n - 1);

    for (size_t i = 0; i < n; ++i) {
        std::cout << v[i] << ' ';
    }
}
