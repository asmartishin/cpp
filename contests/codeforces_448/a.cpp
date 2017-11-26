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


void rotate(vector<int> &pieces, int k) {
    int n = pieces.size();
    int rt = n - k % n - 1;

    int l = 0;
    int r = rt;

    while (l < r)
        swap(pieces[l++], pieces[r--]);

    l = rt + 1;
    r = n - 1;

    while (l < r)
        swap(pieces[l++], pieces[r--]);

    l = 0;
    r = n - 1;

    while (l < r)
        swap(pieces[l++], pieces[r--]);
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.precision(10);

    int n, result = numeric_limits<int>::max(), sum = 0, sumr;
    cin >> n;

    vector<int> pieces(n);

    for (size_t i = 0; i < n; ++i) {
        cin >> pieces[i];
        sum += pieces[i];
    }

    for (size_t i = 0; i < n; ++i) {
        int suml = 0;

        for (size_t j = 0; j < n; ++j) {
            suml += pieces[j];
            sumr = sum - suml;
            result = min(result, abs(sumr - suml));
        }
        rotate(pieces, 1);
    }

    cout << result << endl;

    return 0;
}
