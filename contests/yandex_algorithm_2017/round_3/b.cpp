#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {
    string ns;
    int x, y, max_n, min_n;
    vector<int> n;
    vector<int> result;

    bool lesser = false;

    cin >> ns >> x >> y;
    max_n = max(x, y);
    min_n = min(x, y);

    for (size_t i = 0; i < ns.size(); ++i) {
        n.push_back(ns[i] - '0');
    }

    if (min_n > n[0]) {
        for (size_t i = 0; i < n.size() - 1; ++i) {
            result.push_back(max_n);
        }
    } else {
        for (size_t i = 0; i < n.size(); ++i) {
            if (max_n <= n[i] || lesser) {
                result.push_back(max_n);
            } else if (min_n <= n[i]) {
                result.push_back(min_n);
                lesser = true;
            }
        }
    }

    while (!result.empty()) {
        if (result[0] == 0) {
            result.erase(result.begin());
        } else {
            break;
        }
    }

    if (!result.empty()) {
        for (size_t i = 0; i < result.size(); ++i) {
            cout << result[i];
        }
    } else {
        cout << -1;
    }

    cout << endl;

    return 0;
}
