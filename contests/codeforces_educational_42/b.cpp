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
#include <cassert>
#include <fstream>
#include <array>

using namespace std;

#define endl '\n'

void calculateSubstring(int &substringSize, int &a, int &b) {
    if (substringSize % 2 == 0) {
        a = max(a - substringSize / 2, 0);
        b = max(b - substringSize / 2, 0);
    } else {
        if (a > b) {
            a = max(a - substringSize / 2 - 1, 0);
            b = max(b - substringSize / 2, 0);
        } else {
            a = max(a - substringSize / 2, 0);
            b = max(b - substringSize / 2 - 1, 0);
        }
    }
    substringSize = 0;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.precision(10);

    int n, a, b, substringSize = 0;
    char c;

    cin >> n >> a >> b;

    int initStudents = a + b;

    for (size_t i = 0; i < n; ++i) {
        cin >> c;

        if (c == '.')
            ++substringSize;
        else
            calculateSubstring(substringSize, a, b);
    }

    calculateSubstring(substringSize, a, b);

    cout << initStudents - a  - b << endl;

    return 0;
}
