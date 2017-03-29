#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <unordered_set>
#include <climits>
using namespace std;


int main() {
    long long b, q, l, value;
    int m;
    string result = "inf";
    unordered_set<long long> badValues;
    long long valuesNumber = 0;
    long long n;

    cin >> b >> q >> l >> m;

    for (size_t i = 0; i < m; ++i) {
        cin >> value;
        badValues.insert(value);
    }

    if (b == 0) {
        if (0 != l) {
            if (badValues.find(0) == badValues.end()) {
                result = "inf";
            } else {
                result = "0";
            }
        } else {
            result = "0";
        }
    } else if (q == 0) {
        if (1 != l) {
            if (badValues.find(1) == badValues.end()) {
                result = "inf";
            } else {
                result = "0";
            }
        } else {
            result = "0";
        }
    } else if (abs(b) > l && abs(q) < 1){
        result = "inf";
    } else if (abs(b) > l){
        result = "0";
    } else {
        n = (long long)(log(l / abs(b)) / log(abs(q)));

        if (n == LLONG_MIN || n == LLONG_MAX) {
            if (badValues.find(b) == badValues.end()) {
                result = "inf";
            } else {
                result = "0";
            }
        } else {
            ++n;
            for (size_t i = 0; i < n; ++i) {
                value  = b * pow(q, i);
                if (badValues.find(value) == badValues.end() && abs(value) <= l) {
                    ++valuesNumber;
                }
            }
            result = to_string(valuesNumber);
        }
    }

    cout << result << endl;

    return 0;
}
