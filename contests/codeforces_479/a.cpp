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
#include <limits>
#include <cassert>
#include <fstream>
#include <array>

using namespace std;

#define endl '\n'


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.precision(10);

    int n, k;

    cin >> n >> k;

    for (size_t i = 0; i < k; ++i) {
        if (n % 10 == 0)
            n /= 10;
        else
            n -= 1;
    }

    cout << n << endl;

    return 0;
}
