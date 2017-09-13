#include <iostream>
#include <vector>

using namespace std;


int main() {
    int n, k, j = 1;
    cin >> n >> k;
    vector<int> v(n);

    for (size_t i = 0; i < n; ++i) {
        cin >> v[i];
    }

    for (size_t i = 0; i < n; ++i) {
        if (v[i] > 8) {
            k -= 8;
            if (i + 1 < n) {
                v[i + 1] += v[i] - 8;
            }
        } else {
            k -= v[i];
        }

        if (k <= 0) {
            break;
        }

        ++j;
    }

    if (k > 0) {
        cout << -1 << endl;
    } else {
        cout << j << endl;
    }

    return 0;
}
