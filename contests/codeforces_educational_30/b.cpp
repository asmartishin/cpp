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

    int n, zcount = 0, ocount = 0, result = 0;
    char c;
    map<int, int> m;

    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> c;
        if (c == '0')
            ++ocount;
        else
            ++zcount;
        if (m.find(ocount - zcount) == m.end())
            m[ocount - zcount] = i;
        else
            result = max(result, i - m[ocount - zcount]);

        if (ocount == zcount)
            result = max(result, i + 1);
    }

    cout << result << endl;

    return 0;
}
