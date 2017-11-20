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

    int n, v, a = 0, b = 1023;
    char c;
    cin >> n;

    for (size_t i = 0; i < n; ++i) {
        cin >> c >> v;
        if (c == '|') {
            a |= v;
            b |= v;
        } else if (c == '&') {
            a &= v;
            b &= v;
        } else {
            a ^= v;
            b ^= v;
        }
    }

    cout << 3 << endl << "& " << to_string(a | b) << endl << "^ " << to_string(a & (1023 ^ b)) << endl << "| " << to_string(a & b) << endl;

    return 0;
}
