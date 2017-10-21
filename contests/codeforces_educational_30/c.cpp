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
#include <climits>
#include <cassert>
#include <numeric>

using namespace std;

#define endl '\n'


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.precision(10);

    int n, m, k, rs = 0, rd = 0;

    cin >> n >> m >> k;

    vector<vector<int> > v(n, vector<int>(m));

    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < m; ++j) {
            cin >> v[i][j];
        }
    }

    for (int j = 0; j < m; ++j) {
        int rsc = 0;
        int rdc = 0;
        int prdc = 0;
        for (int i = 0; i < n; ++i) {
            if (v[i][j] == 1) {
                int prsc = 0;
                for (int l = i; l < min(i + k, n); ++l) {
                    if (v[l][j] == 1)
                        ++prsc;
                }
                if (prsc > rsc) {
                    rdc = prdc;
                    rsc = prsc;
                }
                ++prdc;
            }
        }
        rs += rsc;
        rd += rdc;
    }

    cout << rs << ' ' << rd << endl;

    return 0;
}
