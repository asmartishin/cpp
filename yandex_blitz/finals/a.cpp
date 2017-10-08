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


void dfs(vector<vector<bool> > &matrix, set<pair<int, int> > &not_visited, pair<int, int> v, int n, int m) {
    set<pair<int, int> > used;

    stack<pair<int, int> > s;
    s.push(v);

    while (!s.empty()) {
        pair<int, int> cv = s.top();
        s.pop();

        for (auto& nv: {
            make_pair(cv.first + 1, cv.second),
            make_pair(cv.first, cv.second + 1),
            make_pair(cv.first - 1, cv.second),
            make_pair(cv.first, cv.second - 1)
        }) {
            if (nv.first >= 0 && nv.first < n && nv.second >= 0 && nv.second < m) {
                if (used.find(nv) == used.end() && !matrix[nv.first][nv.second]) {
                    s.push(nv);
                    used.insert(nv);
                }
            }
        }
        not_visited.erase(cv);
    }
}


int number_of_components(vector<vector<bool> > &matrix, int n, int m) {
    set<pair<int, int> > not_visited;

    int result = 0;

    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < m; ++j) {
            if (!matrix[i][j]) {
                not_visited.insert(make_pair(i, j));
            }
        }
    }

    while (!not_visited.empty()) {
        pair<int, int> v = *not_visited.begin();
        dfs(matrix, not_visited, v, n, m);
        ++result;
    }

    return result;
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.precision(10);

    int n, m, k, r, c;

    cin >> n >> m >> k;

    vector<vector<bool> > matrix(n, vector<bool>(m, false));

    for (size_t i = 0; i < k; ++i) {
        cin >> r >> c;
        matrix[r - 1][c - 1] = true;
    }

    cout << number_of_components(matrix, n, m) << endl;

    return 0;
}
