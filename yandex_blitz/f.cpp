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


vector<int> multiply_permutations(vector<int> &v1, vector<int> &v2) {
    vector<int> result;

    for (size_t i = 0; i < v1.size(); ++i) {
        result.push_back(v2[v1[i]]);
    }

    return result;
}


vector<int> inverse_permutation(vector<int> &v) {
    vector<int> result(v.size());

    for (size_t i = 0; i < v.size(); ++i) {
        result[v[i]] = i;
    }

    return result;
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.precision(10);

    int n, m, k, v;

    cin >> n >> m;

    vector<vector<int> > p(m, vector<int>(n));
    vector<vector<int> > pp;

    for (size_t i = 0; i < m; ++i) {
        for (size_t j = 0; j < n; ++j) {
            cin >> p[i][j];
            --p[i][j];
        }
    }

    cin >> k;

    cin >> v;

    pp.push_back(p[v - 1]);

    for (size_t i = 1; i < k; ++i) {
        cin >> v;

        pp.push_back(multiply_permutations(pp[i - 1], p[v - 1]));
    }

    for (size_t i = 0; i < k; ++i) {
        vector<int> pt1 = inverse_permutation(pp[i]);
        vector<int> pt2 = multiply_permutations(pt1, pp.back());

        if (i > 0)
            cout << multiply_permutations(pp[i - 1], pt2).front() + 1 << endl;
        else
            cout << pt2.front() + 1 << endl;
    }

    return 0;
}
