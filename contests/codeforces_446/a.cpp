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

    int n;
    long long sum_a = 0, a, b;

    cin >> n;
    vector<long long> array_b;

    for (size_t i = 0; i < n; ++i)  {
        cin >> a;
        sum_a += a;
    }

    for (size_t i = 0; i < n; ++i) {
        cin >> b;
        array_b.push_back(b);
    }

    sort(array_b.begin(), array_b.end());
    reverse(array_b.begin(), array_b.end());

    if (sum_a <= array_b[0] + array_b[1])
        cout << "YES";
    else
        cout << "NO";

    cout << endl;

    return 0;
}
