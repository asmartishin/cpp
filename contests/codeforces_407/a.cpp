#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
    int n;
    long long k;
    long long days = 0;

    cin >> n >> k;

    vector <int> rocks(n);

    for (size_t i = 0; i < n; ++i) {
        cin >> rocks[i];
    }

    std::sort(rocks.begin(), rocks.end());

    for (size_t i = 0; i < n; ++i) {
        while (rocks[i] > 0) {
            if (rocks[i] > k) {
                rocks[i] -= 2 * k;
            } else {
                rocks[i] -= k;
                rocks[i + 1] -= k;
            }
            ++days;
        }
    }

    cout << days << endl;

    return 0;
}
