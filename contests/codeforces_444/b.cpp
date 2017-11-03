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
#include <climits>
#include <cassert>
#include <numeric>

using namespace std;


vector<int> split_number(int n) {
    vector<int> result;
    while (n > 0) {
        result.push_back(n % 10);
        n /= 10;
    }

    reverse(result.begin(), result.end());

    return result;
}

bool n1(vector<vector<bool> > &v, vector<int> &split_result) {
    return v[0][split_result[0]] == true;
}

bool n2(vector<vector<bool> > &v, vector<int> &split_result) {
    if (split_result.size() == 1)
        return v[0][split_result[0]] || v[1][split_result[0]];
    else
        return (v[0][split_result[0]] && v[1][split_result[1]]) ||  (v[0][split_result[1]] && v[1][split_result[0]]);
}

bool n3(vector<vector<bool> > &v, vector<int> &split_result) {
    if (split_result.size() == 1)
        return v[0][split_result[0]] || v[1][split_result[0]] || v[2][split_result[0]];
    else if (split_result.size() == 2)
        return (v[0][split_result[0]] && v[1][split_result[1]]) || (v[1][split_result[0]] && v[0][split_result[1]]) ||
            (v[0][split_result[0]] && v[2][split_result[1]]) || (v[2][split_result[0]] && v[0][split_result[1]]) ||
            (v[1][split_result[0]] && v[2][split_result[1]]) || (v[2][split_result[0]] && v[1][split_result[1]]);
    else
        return (v[0][split_result[0]] && v[1][split_result[1]] && v[2][split_result[2]]) ||
            (v[0][split_result[0]] && v[1][split_result[2]] && v[2][split_result[1]]) ||
            (v[0][split_result[1]] && v[1][split_result[0]] && v[2][split_result[2]]) ||
            (v[0][split_result[1]] && v[1][split_result[2]] && v[2][split_result[0]]) ||
            (v[0][split_result[2]] && v[1][split_result[0]] && v[2][split_result[1]]) ||
            (v[0][split_result[2]] && v[1][split_result[1]] && v[2][split_result[0]]);
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.precision(10);

    int n, result = 0, value, m;

    cin >> n;

    vector<vector<bool> > v(n, vector<bool>(10, false));
    vector<int> split_result;

    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < 6; ++j) {
            cin >> value;
            v[i][value] = true;
        }
    }

    while (true) {
        ++result;

        split_result = split_number(result);
        m = split_result.size();

        if (m > n) {
            cout << result - 1 << endl;
            return 0;
        }

        if (((n == 1) && n1(v, split_result)) || ((n == 2) && n2(v, split_result)) || ((n == 3) && n3(v, split_result)))
            continue;

        cout << result - 1 << endl;
        return 0;
    }

    return 0;
}
