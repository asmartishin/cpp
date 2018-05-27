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
#include <limits>
#include <cassert>
#include <fstream>
#include <array>

using namespace std;

#define endl '\n'

int main() {
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.precision(10);

    int n, k, color;
    cin >> n >> k;

    vector<int> groups(256, -1);

    for (size_t i = 0; i < n; ++i) {
        cin >> color;

        if (groups[color] == -1) {
            int otherColor = max(color - k + 1, 0);

            while (groups[otherColor] != -1 && color - groups[otherColor] >= k)
                ++otherColor;

            for (size_t i = otherColor; i <= color; ++i)
                groups[i] = otherColor;

            cout << groups[color] << ' ';
        } else {
            cout << groups[color] << ' ';
        }
    }

    cout << endl;

    return 0;
}
