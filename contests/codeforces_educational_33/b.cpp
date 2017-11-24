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


struct TSetReversOrder {
    bool operator()(const int &v1, const int &v2) const {
        return v1 > v2;
    }
};


bool isNumberPerfect(int v) {
    vector<int> bit_repr;

    while (v) {
        bit_repr.push_back(v % 2);
        v /= 2;
    }

    reverse(bit_repr.begin(), bit_repr.end());

    if (bit_repr.size() % 2 == 0)
        return false;

    int k = (bit_repr.size() - 1) / 2;
    int i = 0;

    while (i < k + 1) {
        if (bit_repr[i++] != 1)
            return false;
    }

    while (i < 2 * k + 1) {
        if (bit_repr[i++] != 0)
            return false;
    }

    return true;
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.precision(10);

    int n;
    cin >> n;
    set<int, TSetReversOrder> divisors;
    divisors.insert(1);

    for (int i = 1; i <= sqrt(n); ++i) {
        if (n % i == 0) {
            divisors.insert(i);
            divisors.insert(n / i);
        }
    }

    for (auto const &v: divisors) {
        if (isNumberPerfect(v)) {
            cout << v << endl;
            return 0;
        }
    }

    return 0;
}
