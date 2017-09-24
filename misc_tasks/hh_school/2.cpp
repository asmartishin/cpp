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

using namespace std;

#define endl '\n'


bool isPrime(int n) {
    for (size_t i = 2; i * i <= n; i++)
        if (n % i == 0) {
            return false;
        }
    return true;
}


bool P(int n, int k) {
    if (n < 2 * k) {
        return false;
    }

    if (k == 1) {
        return isPrime(n);
    }

    if (k == 2) {
        if (n % 2 == 0) {
            return true;
        }
        return isPrime(n - 2);
    }

    return true;
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.precision(10);

    int size = 11364;
    long long result = 0;

    for (size_t n = 1; n <= size; ++n) {
        for (size_t k = 1; k <= size; ++k) {
            result += P(n, k) ? 1 : 0;
        }
    }

    cout << result << endl;

    return 0;
}
