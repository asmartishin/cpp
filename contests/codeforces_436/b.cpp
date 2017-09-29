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

    int n, result = 0, max_result = 0;
    cin >> n;

    vector<char> v(n);

    for (size_t i = 0; i < n; ++i) {
        cin >> v[i];
    }

    for (size_t i = 0; i < n; ++i) {
        if (isupper(v[i]))
            continue;

        result = 1;
        set<char> s;
        s.insert(v[i]);

        for (size_t j = i + 1; j < n; ++j) {
            if (isupper(v[j]))
                break;
            else {
                if (s.find(v[j]) == s.end()) {
                    s.insert(v[j]);
                    ++result;
                }
            }
        }
        max_result = max(result, max_result);
    }

    cout << max_result << endl;

    return 0;
}
