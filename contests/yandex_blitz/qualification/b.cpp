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

using namespace std;

#define endl '\n'


int S(int k) {
    int sum = 0;
    while (k > 0) {
        sum += k % 10;
        k /= 10;
    }

    return sum;
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.precision(10);

    set<double> s;

    for (size_t n = 1; n < 1e6; ++n) {
        s.insert(n);
    }

    for (size_t k = 0; k < 1e6; ++k) {
        double nk = (double)(3 * k) / (double)pow(S(k), 2);
        if (s.find(nk) != s.end()) {
            s.erase(nk);
        }
    }

    cout << *s.begin() << endl;

    return 0;
}
