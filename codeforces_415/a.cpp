#include <iostream>
#include <vector>
#include <cmath>

using namespace std;


double mark(vector<int> &v) {
    double sum = 0.0;
    for (size_t i = 0; i < v.size(); ++i) {
        sum += v[i];
    }
    return floor(sum / v.size() + 0.5);
}


int main() {
    int n, k, m, result = 0;
    cin >> n >> k;

    vector<int> v(n);

    for (size_t i = 0; i < n; ++i) {
        cin >> m;
        v[i] = m;
    }

    while (mark(v) != k) {
        v.push_back(k);
        ++result;
    }

    cout << result << endl;

    return 0;
}
