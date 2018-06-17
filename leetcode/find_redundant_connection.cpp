#include <iostream>
#include <vector>
#include <unordered_set>
#include <stack>

using namespace std;


bool is_divided_dfs(vector<vector<int> > &graph, int exclude_edge_begin, int exclude_edge_end) {
    unordered_set<int> visited(graph.size());
    stack<int> s;

    s.push(0);

    while (!s.empty()) {
        int v = s.top();
        s.pop();

        for (auto const &i: graph[v]) {
            if (visited.find(i) == visited.end() && !(
                (exclude_edge_begin == v && exclude_edge_end == i) ||
                (exclude_edge_begin == i && exclude_edge_end == v)
            )) {
                s.push(i);
                visited.insert(i);
            }
        }
    }

    return visited.size() == graph.size();
}


vector<int> findRedundantConnection(vector<vector<int> > &edges) {
    int n = edges.size();
    vector<vector<int> > graph(n, vector<int>());
    vector<int> result;

    for (size_t i = 0; i < n; ++i) {
        int x = edges[i].front();
        int y = edges[i].back();
        graph[x - 1].push_back(y - 1);
        graph[y - 1].push_back(x - 1);
    }

    for (auto const &v: edges) {
        int exclude_edge_begin = v.front();
        int exclude_edge_end = v.back();

        if (is_divided_dfs(graph, exclude_edge_begin - 1, exclude_edge_end - 1))
            result = {exclude_edge_begin, exclude_edge_end};
    }

    return result;
}


int main() {
    vector<vector<int> > edges{{1, 2}, {2, 3}, {3, 4}, {1, 4}, {1, 5}};

    for (auto const &v: findRedundantConnection(edges))
        cout << v << ' ';
    cout << endl;

    return 0;
}
