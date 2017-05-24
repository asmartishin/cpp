#include <iostream>
#include <vector>
#include <cmath>

using namespace std;


int main() {
    int n, d;
    cin >> n;

    long long result = 1;

    for (size_t i = 0; i < n; ++i) {
        cin >> d;
        result *= d;
    }

    cout << result / 256 << endl;

    return 0;
}
