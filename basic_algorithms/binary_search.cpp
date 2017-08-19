#include <iostream>
#include <vector>

using namespace std;

int binarySearchRecursive(const vector<int> &v, int s, int l, int r) {
    if (l > r) {
        return -1;
    }

    int m = (l + r) / 2;

    if (v[m] < s) {
        return binarySearchRecursive(v, s, ++m, r);
    } else if (v[m] > s) {
        return binarySearchRecursive(v, s, l, --m);
    } else {
        return m;
    }
}

int binarySearchIterative(const vector<int> &v, int s) {
    int l = 0;
    int r = v.size() - 1;
    int m;

    while (l <= r) {
        m = (l + r) / 2;
        if (v[m] < s) {
            l = ++m;
        } else if (v[m] > s) {
            r = --m;
        } else {
            return m;
        }
    }

    return -1;
}


int main() {
    int n, s;

    cin >> n;
    vector<int> v(n);

    for (size_t i = 0; i < n; ++i) {
        cin >> v[i];
    }

    cin >> s;

    cout << binarySearchRecursive(v, s, 0, v.size() - 1) << endl;
    cout << binarySearchIterative(v, s) << endl;
}
