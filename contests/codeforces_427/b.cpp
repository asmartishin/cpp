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


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.precision(10);

    int k, sum = 0, v, result = 0;
    map<int, int> c = {{0, 0}, {1, 0}, {2, 0}, {3, 0}, {4, 0}, {5, 0}, {6, 0}, {7, 0}, {8, 0}, {9, 0}};
    string n;

    cin >> k >> n;

    for (size_t i = 0; i < n.size(); ++i) {
        v = n[i] - '0';
        ++c[v];
        sum += n[i] - '0';
    }

    int i = 0;

    while (sum < k) {
        v = 9 - i;
        if (v * c[i] < k - sum) {
            sum += v * c[i];
            result += c[i];
        } else {
            result += ceil((k - sum) / (double)v);
            break;
        }
        ++i;
    }

    cout << result << endl;

    return 0;
}
