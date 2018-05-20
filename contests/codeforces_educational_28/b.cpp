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

    int n, k, m, result = 0, sumTime = 0, sumCost;
    cin >> n >> k >> m;

    vector<int> t(k);

    for (size_t i = 0; i < k; ++i) {
        cin >> t[i];
        sumTime += t[i];
    }

    sumCost = k + 1;
    sort(t.begin(), t.end());

    for (size_t i = 0; i <= n; ++i) {
        int remainingTime = m - i * sumTime;

        if (remainingTime < 0) {
            break;
        }

        int newResult = sumCost * i;

        for (const auto subProblemTime: t) {
            int countSolved = min((int)(n - i), remainingTime / subProblemTime);
            newResult += countSolved;
            remainingTime -= countSolved * subProblemTime;
        }

        result = max(result, newResult);
    }

    cout << result << endl;

    return 0;
}
