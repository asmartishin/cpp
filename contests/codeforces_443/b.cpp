#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <limits>
#include <cassert>
#include <numeric>

using namespace std;

#define endl '\n'


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.precision(10);

    deque<int> dq;

    long long k;
    int n, w = 0, p;
    cin >> n >> k;

    vector<int> wins(n, 0);

    if (k < 2 * n) {
        for (size_t i = 0; i < n; ++i) {
            cin >> p;
            dq.push_back(p);
        }
        while (true) {
            int p1 = dq.front();
            dq.pop_front();
            int p2 = dq.front();
            dq.pop_front();

            if (p1 > p2) {
                dq.push_front(p1);
                dq.push_back(p2);
                ++wins[p1 - 1];

                if (wins[p1 - 1] == k) {
                    w = p1;
                    break;
                }
            } else {
                dq.push_front(p2);
                dq.push_back(p1);
                ++wins[p2 - 1];

                if (wins[p2 - 1] == k) {
                    w = p2;
                    break;
                }
            }
        }
    } else {
        for (size_t i = 0; i < n; ++i) {
            cin >> p;
            w = max(w, p);
        }
    }

    cout << w << endl;

    return 0;
}
