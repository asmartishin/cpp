#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <limits>
#include <cassert>
#include <numeric>

using namespace std;

#define endl '\n'


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.precision(10);

    string s_in, s = "", p;
    int result = 0;
    getline (cin, s_in);

    p = "QAQ";

    int n = s_in.size();

    for (size_t i = 0; i < n; ++i) {
        if (s_in[i] == 'Q' || s_in[i] == 'A')
            s += s_in[i];
    }

    int m = s.size();

    for (size_t i1 = 0; i1 < m; ++i1) {
        for (size_t i2 = i1; i2 < m; ++i2) {
            for (size_t i3 = i2; i3 < m; ++i3) {
                string s_t = "";
                s_t += s[i1];
                s_t += s[i2];
                s_t += s[i3];

                if (p == s_t)
                    ++result;
            }
        }
    }

    cout << result << endl;

    return 0;
}
