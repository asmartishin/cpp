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

using namespace std;

#define endl '\n'


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.precision(10);

    int n, k, br, gr;

    cin >> n >> k;

    if (k == 0 || k == n) {
        br = 0;
    } else {
        br = 1;
    }

    if (k <= (n / 3)) {
        gr = 2 * k;
    } else {
        if (k == 0) {
            gr = 0;
        } else {
            gr = n - k;
        }
    }

    cout << br << ' ' << gr << endl;

    return 0;
}
