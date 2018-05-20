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
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.precision(10);

    long long n;
    cin >> n;

    vector<long long> a(n);

    array<long long, 3>result{ {0, 0, 0} };
    long long resultSum = numeric_limits<long long>::min();

    for (size_t i = 0; i < n; ++i)
        cin >> a[i];

    vector<long long> prefixSums(n + 1, 0);

    for (size_t i = 1; i <= n; ++i)
        prefixSums[i] = prefixSums[i - 1] + a[i - 1];

    for (size_t d0 = 0; d0 <= n; ++d0) {
        size_t d1;

        long long minPrefixSum = numeric_limits<long long>::max();
        long long newResultSum;

        for (size_t d2 = d0; d2 <= n; ++d2) {
            if (prefixSums[d2] < minPrefixSum) {
                d1 = d2;
                minPrefixSum = prefixSums[d2];
            }

            newResultSum = prefixSums[d0] - (prefixSums[d1] - prefixSums[d0]) + (prefixSums[d2] - prefixSums[d1]) - (prefixSums[n] - prefixSums[d2]);

            if (d2 >= d1 && newResultSum > resultSum) {
                resultSum = newResultSum;
                result[0] = d0;
                result[1] = d1;
                result[2] = d2;
            }
        }
    }

    for (const auto &v: result)
        cout << v << ' ';
    cout << endl;

    return 0;
}
