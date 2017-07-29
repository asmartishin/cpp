#include <iostream>

using namespace std;


int quickSortPartition(vector<int>& v, int ) {
    int x =
}

void quickSortRecursive(vector<int>& v, int l, int r) {
    if (l < r) {
        int p = quickSortPartition(v, l, r);
        quickSortRecursive(v, l, r - 1);
        quickSortRecursive(v, p + 1, r);
    }
}

int main() {
    int n;
    vector<int> v;

    cout << "Input array: ";
    while (cin >> n)
        v.push_back(n);

    for (size_t i = 0; i < v.size(); ++i) {
        cout << v[i] << ' ';
    }
    cout << endl;

    quickSortRecursive(v, 0, v.size() - 1)

    return 0;
}
