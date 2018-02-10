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

    int n, result = 0;
    cin >> n;

    for (size_t a = 1; a <= n; ++a) {
        for (size_t b = a; b <= n; ++b) {
            int c = a ^ b;

            if (c <= n && c >= b && c != a + b)
                ++result;
        }
    }

    cout << result << endl;

    return 0;
}
