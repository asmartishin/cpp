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
#include <array>


using namespace std;

#define endl '\n'


struct TPairHash {
    template<typename T1, typename T2>
    inline size_t operator()(const pair<T1, T2> &p) const {
        return hash<T1>()(p.first) ^ hash<T2>()(p.second);
    }
};


struct Cell {
    pair<int, int> coordinates;
    int value;
    string path;

    Cell(pair<int, int> c, int value, string s)
        : coordinates(c), value(value), path(s) {}
};


array<Cell, 4> get_neighbours(int y, int x) {
    return {
        Cell(make_pair(y, x - 1), 0, "W"),
        Cell(make_pair(y + 1, x), 0, "S"),
        Cell(make_pair(y, x + 1), 0, "E"),
        Cell(make_pair(y - 1, x), 0, "N")
    };
}


// pair<int, int> c - y, x
void dfs(vector<vector<int> > &matrix, pair<int, int> &edge_coordinates, unordered_set<pair<int, int>, TPairHash> visited, set<pair<int, string> > &paths, Cell cell) {
    visited.insert(cell.coordinates);

    bool has_neighbours = false;
    for (auto &nb: get_neighbours(cell.coordinates.first, cell.coordinates.second)) {
        if (
            nb.coordinates.first < edge_coordinates.first
            && nb.coordinates.first >= 0
            && nb.coordinates.second < edge_coordinates.second
            && nb.coordinates.second >= 0
            && (visited.find(nb.coordinates) == visited.end())
        ) {
            has_neighbours = true;
            nb.path = cell.path + nb.path;
            nb.value = cell.value + (cell.value % matrix[nb.coordinates.first][nb.coordinates.second]);
            dfs(matrix, edge_coordinates, visited, paths, nb);
        }
    }

    visited.erase(cell.coordinates);

    if (!has_neighbours && cell.path.size() == edge_coordinates.first * edge_coordinates.second - 1)
        paths.insert(make_pair(cell.value, cell.path));
}


void solve() {
    int m, n;
    cin >> m >> n;

    pair<int, int> edge_coordinates = make_pair(n, m);
    vector<vector<int> > matrix(n, vector<int>(m));
    pair<int, string> result{numeric_limits<int>::max(), ""};
    pair<int, int> result_coordinates;

    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < m; ++j) {
            cin >> matrix[i][j];
        }
    }

    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < m; ++j) {
            unordered_set<pair<int, int>, TPairHash> visited;
            set<pair<int, string> > paths;
            visited.insert(make_pair(i, j));
            dfs(matrix, edge_coordinates, visited, paths, Cell(make_pair(i, j), matrix[i][j] == 1 ? 1 : 2, ""));
            auto tmp_result = *paths.begin();
            if (tmp_result.first < result.first) {
                result = tmp_result;
                result_coordinates = make_pair(i, j);
            }
        }
    }
    cout << result_coordinates.second + 1 << ' ' << result_coordinates.first + 1 << endl
    << result.second << endl << result.first << endl;
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.precision(10);

    int t;
    cin >> t;

    for (size_t i = 0; i < t; ++i)
        solve();

    return 0;
}
