#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {
    long long result = 0;
    int n, f, m, p;
    cin >> n >> f;

    vector< pair<int, int> > v(n);

    for (size_t i = 0; i < n; ++i) {
        cin >> m >> p;
        v[i] = make_pair(min(m, p), min(m * 2, p));
    }

    sort(v.begin(), v.end(), [](pair<int, int> &left, pair<int, int> &right) {
        return left.second > right.second;
    });

    for (size_t i = 0; i < n; ++i) {
        if (f == 0) {
            result += v[i].first;
        } else {
            result += v[i].second;
            --f;
        }
    }

    cout << result << endl;

    return 0;
}
