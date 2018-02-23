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

    int n;
    cin >> n;
    long long result = 1;
    int d = 1e9 + 7;

    for (size_t i = n; i > 1; --i) {
        for (size_t j = 1; j < 2 * i - 2; ++j) {
            result *= n;
            result %= d;
        }
    }

    cout << result;

    return 0;
}
