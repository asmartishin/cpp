#include <iostream>
#include <vector>

using namespace std;


int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    bool inc=true, eq=false, dec=false, result=true;

    for (size_t i = 0; i < n; ++i) {
        cin >> a[i];
    }

    for (size_t i = 0; i < n - 1; ++i) {
        if (a[i] < a[i + 1]) {
            if (inc) {
                continue;
            } else {
                result = false;
                break;
            }
        } else if (a[i] == a[i + 1]) {
            if (eq) {
                continue;
            } else if (inc) {
                eq = true;
                inc = false;
            } else {
                result = false;
                break;
            }
        } else if (a[i] > a[i + 1]) {
            if (dec) {
                continue;
            } else if (eq || inc) {
                eq = false;
                inc = false;
                dec = true;
            } else {
                result = false;
                break;
            }
        }
    }

    if (result) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
