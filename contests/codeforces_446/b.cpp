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

    int n = 0, alive = 1;
    cin >> n;

    vector<int> claws(n);

    for (int i = 0; i < n; ++i)
        cin >> claws[i];

    int x = n - 1 - claws[n - 1];
    for (int i = n - 1; i >= 0; --i) {
        if (i < x)
            ++alive;
        x = min(x, i - claws[i]);
    }

    cout << alive << endl;

    return 0;
}
