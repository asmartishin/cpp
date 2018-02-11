#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <climits>
#include <cassert>

using namespace std;

#define endl '\n'


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.precision(10);

    long long int n, t, r, x, y;

    cin >> n;

    set<pair<long long int, long long int> > centers;

    for (size_t i = 0; i < n; ++i) {
        cin >> t;

        if (t == 0) {
            cin >> r >> x >> y;
            x *= 2;
            y *= 2;
            centers.insert(make_pair(x, y));
        } else {
            cin >> x >> y;
            x *= 2;
            y *= 2;
            pair<long long int, long long int> p1 = make_pair(x, y);

            cin >> x >> y;

            cin >> x >> y;
            x *= 2;
            y *= 2;
            pair<long long int, long long int> p3 = make_pair(x, y);

	    cin >> x >> y;

            centers.insert(
                    make_pair(
                        (p1.first + p3.first) / 2,
                        (p1.second + p3.second) / 2
                    )
            );
        }
    }

    if (centers.size() <= 2) {
        cout << "Yes" << endl;
        return 0;
    } else {
        pair<long long int, long long int> c1 = *centers.begin();
        centers.erase(c1);

        pair<long long int, long long int> c2 = *centers.begin();
        centers.erase(c2);

        long long int lx = c1.second - c2.second;
        long long int ly = c2.first - c1.first;
        long long int lc = c1.first * c2.second - c2.first * c1.second;

        for (auto const &v: centers) {
            if (lx * v.first + ly * v.second + lc != 0) {
                cout << "No" << endl;
                return 0;
            }
        }
    }

    cout << "Yes" << endl;

    return 0;
}

