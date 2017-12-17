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

    int steps_minus = 0, steps_plus = 0, n_minus = n, n_plus = n;

    while (n_minus % 10 != 0) {
        --n_minus;
        ++steps_minus;
    }

    while (n_plus % 10 != 0) {
        ++n_plus;
        ++steps_plus;
    }

    cout << ((steps_minus <= steps_plus) ? n_minus: n_plus) << endl;

    return 0;
}
