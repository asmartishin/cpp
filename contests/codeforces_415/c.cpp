#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;


int main() {
    int n, c, result = 0, d, modulo = 1000000007;
    cin >> n;

    vector<int> v(n);
    vector<long long int> p(n + 1);

    for (size_t i = 0; i < n; ++i) {
        cin >> c;
        v[i] = c;
    }

    sort(v.begin(), v.end());

    p[0] = 1;

    for (size_t i = 1; i < n + 1; ++i) {
        p[i] = (p[i - 1] * 2) % modulo;
    }

    for (size_t i = 1; i < n; ++i) {
        d = v[i] - v[i - 1];
	d *= p[i] - 1;
	d %= modulo;
        d *= p[n - i] - 1;
        d %= modulo;
        result += d % modulo;
    }

    cout << result << endl;

    return 0;
}
