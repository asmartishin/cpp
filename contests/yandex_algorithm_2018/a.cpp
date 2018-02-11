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

    int h, m, rh, rm;

    cin >> h >> m;

    if (h >= 6)
        rh = 12 - h;
    else
        rh = 6 + (6 - h);

    if (rh == 12)
        rh = 0;

    if (m >= 30)
        rm = 60 - m;
    else
        rm = 30 + (30 - m);

    if (rm == 60)
        rm = 0;

    cout << rh << ' ' << rm << endl;

    return 0;
}
