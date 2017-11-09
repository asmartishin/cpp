#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


int partition(vector<int> &v, int l, int r, int pivot) {
    swap(v[pivot], v[l]);
    int p = l;

    for (size_t i = l + 1; i < r; ++i) {
        if (v[i] >= v[l]) {
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
    } else {
        return v[l];
    }
}


int main() {
    vector<int> nums{1, 1, 1, 2, 2, 3};
    int k = 2;

    vector<int> occurances;
    vector<int> result;
    --k;

    unordered_map<int, int> m;

    for (auto const& v: nums)
        ++m[v];

    for (auto const& v: m)
        occurances.push_back(v.second);

    int top_frequent = quickSelect(occurances, 0, occurances.size(), k);
    cout << top_frequent << endl;

    for (auto const& v: m) {
        if (v.second >= top_frequent)
            result.push_back(v.first);
    }

    for (auto const& v: result)
        cout << v << endl;

    return 0;
}
