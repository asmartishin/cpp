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

    int n;
    cin >> n;

    vector<int> result;

    vector<vector<int> > matrix(n, vector<int>(n));

    unordered_map<int, vector<vector<int> > > data;

    for (size_t i = 0; i < 2 * n; ++i) {
        vector<int> input(n);
        for (size_t j = 0; j < n; ++j)
            cin >> input[j];
        data[input[0]].push_back(input);
    }

    for (auto const &v: data) {
        if (v.second.size() == 2) {
            const vector<int> &v1 = v.second[0];
            const vector<int> &v2 = v.second[1];

            for (size_t i = 0; i < n; ++i)
                matrix[0][i] = v1[i];

            for (size_t i = 0; i < n; ++i)
                matrix[i][0] = v2[i];
        }
    }

    for (size_t i = 0; i < n; ++i) {
        vector<int> &v = data[matrix[i][0]][0];
        for (size_t j = 0; j < n; ++j) {
            matrix[i][j] = v[j];
        }
    }

    for (auto const &r: matrix) {
        for (auto const &v: r) {
            result.push_back(v);
        }
    }

    for (size_t i = 0; i < result.size(); ++i)
        cout << result[i] << ' ';

    cout << endl;

    return 0;
}
