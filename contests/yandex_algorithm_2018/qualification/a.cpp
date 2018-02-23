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

using namespace std;

#define endl '\n'


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.precision(10);

    int n, s;
    unordered_set<int> w;

    for (size_t i = 0; i < 10; ++i) {
        cin >> n;
        w.insert(n);
    }

    cin >> s;

    for (size_t i = 0; i < s; ++i) {
        int lucky = 0;
        for (size_t j = 0; j < 6; ++j) {
            cin >> n;
            if (w.find(n) != w.end())
                ++lucky;
        }

        if (lucky >= 3)
            cout << "Lucky" << endl;
        else
            cout << "Unlucky" << endl;
    }

    return 0;
}
