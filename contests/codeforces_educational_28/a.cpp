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

    int n;
    cin >> n;

    vector<int> s(n);

    for (size_t i = 0; i < n; ++i) {
        cin >> s[i];
    }

    vector<int> prefixZeroes(n);
    vector<int> suffixOnes(n);

    int zeroesCount = 0;
    int onesCount = 0;

    int result = 0;

    for (size_t i = 0; i < n; ++i) {
        if (s[i] == 0)
            ++zeroesCount;

        prefixZeroes[i] = zeroesCount;
    }

    for (int i = n - 1; i >= 0; --i) {
        if (s[i] == 1)
            ++onesCount;

        suffixOnes[i] = onesCount;
    }

    for (size_t i = 0; i < n; ++i) {
        result = max(result, suffixOnes[i] + prefixZeroes[i]);
    }

    cout << result << endl;

    return 0;
}
