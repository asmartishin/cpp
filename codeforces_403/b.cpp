#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;



int main() {
    int n;
    cin >> n;

    vector<long long> x(n);
    vector<long long> v(n);

    for (size_t i = 0; i != n; ++i) {
        cin >> x[i];
    }

    for (size_t i = 0; i != n; ++i) {
        cin >> v[i];
    }

    double min_time = 0;
    double max_time = 1e9;
    double center_time;

    double maxLeft;
    double minRight;

    while (max_time - min_time > 1e-6) {
        center_time = (min_time + max_time) / 2.0;
        for (size_t i = 0; i != n; ++i) {
            if (i == 0) {
                maxLeft = x[0] - center_time * v[0];
                minRight = x[0] + center_time * v[0];
            }
            maxLeft = max(maxLeft, x[i] - center_time * v[i]);
            minRight = min(minRight, x[i] + center_time * v[i]);
        }
        if (maxLeft <= minRight) {
            max_time = center_time;
        } else {
            min_time = center_time;
        }
    }

    cout.precision(12);
    cout << max_time << endl;

    return 0;
}
