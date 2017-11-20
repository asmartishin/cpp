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

    int n, s, d, cd = 1;
    cin >> n;

    for (size_t i = 0; i < n; ++i) {
        cin >> s >> d;
        if (s != cd) {
            while (s < cd)
                s += d;
            cd += s - cd;
        }
        ++cd;
    }

    cout << cd - 1 << endl;

    return 0;
}
