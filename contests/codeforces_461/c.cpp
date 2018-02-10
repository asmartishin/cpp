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


long long gcd(long long v1, long long v2) {
    while (v2 > 0) {
        v1 %= v2;
        swap(v1, v2);
    }
    return v1;
}


long long lcm(long long v1, long long v2) {
    return v1 * v2 / gcd(v1, v2);
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.precision(10);

    long long n;
    long long k;

    cin >> n >> k;
    long long result_lcm = 1;

    if (k >= 43) {
        cout << "No";
    } else {
        for (size_t i = 2; i <= k; ++i)
            result_lcm = lcm(result_lcm, i);

        if ((n + 1) % result_lcm == 0)
            cout << "Yes";
        else
            cout << "No";
    }

    cout << endl;

    return 0;
}
