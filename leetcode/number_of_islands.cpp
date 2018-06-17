#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;


struct TPairHash {
    size_t operator()(const pair<int, int> &p) const {
        return p.first ^ p.second;
    }
};


void dfs(vector<vector<char> > &grid, unordered_set<pair<int, int>, TPairHash > &nodes, pair<int, int> node, int n, int m) {
    nodes.erase(node);
    vector<pair<int, int> > neighbours{{-1, 0} , {1, 0}, {0, -1}, {0, 1}};

    for (auto const &nb: neighbours) {
        int n_first = node.first + nb.first;
        int n_second = node.second + nb.second;
        if (n_first >= 0 && n_first < n
            && n_second >= 0 && n_second < m
            && grid[n_first][n_second] == '1'
        ) {
            pair<int, int> new_node = make_pair(n_first, n_second);
            if (nodes.find(new_node) != nodes.end())
                dfs(grid, nodes, new_node, n, m);
        }
    }
}


int numIslands(vector<vector<char> > &grid) {
    int n = grid.size();

    if (n == 0)
        return 0;

    int m = grid[0].size();
    int result = 0;

    unordered_set<pair<int, int>, TPairHash > nodes;

    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < m; ++j) {
            if (grid[i][j] == '1')
                nodes.insert(make_pair(i, j));
        }
    }

    while (!nodes.empty()) {
        pair<int, int> node = *nodes.begin();
        dfs(grid, nodes, node, n, m);
        ++result;
    }

    return result;
}


int main() {
    vector<vector<char> > grid = {
        {'1', '1', '0', '0', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '1', '0', '0'},
        {'0', '0', '0', '1', '1'},
    };

    cout << numIslands(grid) << endl;

    return 0;
}
