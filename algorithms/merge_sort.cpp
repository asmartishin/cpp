#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int min(int x, int y) { return x < y ? x : y; }

void mergeSortMerge(vector<int> &v, int l, int m, int r);


void mergeSortRecursive(vector<int> &v, int l, int r) {
    if (l < r) {
        int m = (l + r) / 2;
        mergeSortRecursive(v, l, m);
        mergeSortRecursive(v, m + 1, r);
        mergeSortMerge(v, l, m, r);
    }
}

void mergeSortIterative(vector<int> &v, int n) {
    for (size_t c = 1; c <= n - 1; c *= 2) {
        for (size_t l = 0; l < n - 1; l += 2 * c) {
            int m = l + c - 1;
            int r = min(l + 2 * c - 1, n - 1);
            mergeSortMerge(v, l, m, r);
        }
    }
}


void mergeSortMerge(vector<int> &v, int l, int m, int r) {
    int i = 0, j = 0, k = l;
    int lp = m - l + 1;
    int rp = r - m;

    vector<int> L(lp), R(rp);

    for (size_t i = 0; i < lp; ++i) {
        L[i] = v[l + i];
    }

    for (size_t i = 0; i < rp; ++i) {
        R[i] = v[m + 1 + i];
    }

    while (i < lp && j < rp) {
        if (L[i] <= R[j]) {
            v[k++] = L[i++];
        } else {
            v[k++] = R[j++];
        }
    }

    while (i < lp) {
        v[k++] = L[i++];
    }

    while (j < rp) {
        v[k++] = R[j++];
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

//    mergeSortRecursive(v, 0, v.size() - 1);
    mergeSortIterative(v, v.size());

    cout << "Sorted array: ";
    for (size_t i = 0; i < v.size(); ++i) {
        cout << v[i] << ' ';
    }
    cout << endl;

    return 0;
}
