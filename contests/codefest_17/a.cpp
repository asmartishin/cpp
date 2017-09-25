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

using namespace std;

#define endl '\n'


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.precision(10);

    int n;
    set<string> s;
    string v;

    cin >> n;

    for (size_t i = 0; i < n; ++i) {
        cin >> v;
        if (s.find(v) != s.end()) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
            s.insert(v);
        }
    }

    return 0;
}
