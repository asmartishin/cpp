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
#include <limits>
#include <cassert>
#include <fstream>
#include <array>

using namespace std;

#define endl '\n'


int main() {
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.precision(10);

    long long n, m, k;

    cin >> n >> m >> k;
    int rowResult, columnResult;

    if (k < n) {
        rowResult = k + 1;
        columnResult = 1;
    } else if (k < n + m - 1) {
        rowResult = n;
        columnResult = k - n + 2;
    } else {
        k -= n + m - 1;
        auto row = k / (m - 1);
        auto column = k % (m - 1);

        rowResult = n - row - 1;

        if (row % 2 == 0) {
            columnResult = m - column;
        } else {
            columnResult = 2 + column;
        }
    }

    cout << rowResult << ' ' << columnResult << endl;

    return 0;
}
