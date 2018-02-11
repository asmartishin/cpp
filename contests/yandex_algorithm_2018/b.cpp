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

    string s, r;
    int min_lenght = 3;
    getline(cin, s);

    set<string> palindromes;

    for (int i = 0; i < s.size(); ++i) {
        if (i - 1 >= 0 && s[i - 1] == s[i]) {
            if (min_lenght > 2)
                min_lenght = 2;
            palindromes.insert(s.substr(i - 1, 2));
        }

        if (i + 1 < s.size() && s[i + 1] == s[i]) {
            if (min_lenght > 2)
                min_lenght = 2;
            palindromes.insert(s.substr(i, 2));
        }

        if (i - 1 >= 0 && i + 1 < s.size() && s[i - 1] == s[i + 1] && s[i - 1] != s[i]) {
            palindromes.insert(s.substr(i - 1, 3));
        }
    }

    if (!palindromes.empty()) {
        for (const auto &v: palindromes) {
            if (v.length() == min_lenght) {
                cout << v << endl;
                return 0;
            }
        }
    }

    cout << -1 << endl;

    return 0;
}
