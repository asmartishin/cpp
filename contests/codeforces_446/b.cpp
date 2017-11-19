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

    int n = 0, claw;
    cin >> n;

    vector<long long> dead(n, 0);
    dead[0] = 0;
    cin >> claw;

    for (int i = 1; i < n; ++i) {
        cin >> claw;

        if (claw == 0)
            dead[i] = dead[i - 1];
        else if ((i - claw) > 0)
            dead[i] = max(dead[i - claw] + claw, dead[i - 1] + 1);
        else
            dead[i] = i;
    }

    cout <<  (n - dead.back()) << endl;

    return 0;
}
