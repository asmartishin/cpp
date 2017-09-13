#include <iostream>
#include <vector>

using namespace std;


void dfs(const vector<vector<int> >graph, const int v, vector<bool> &used, vector<int> &result) {
    used[v] = true;
    for (size_t i = 0; i < graph[v].size(); ++i) {
        const int av = graph[v][i];
        if (!used[av]) {
            dfs(graph, av, used, result);
        }
    }
    result.push_back(v);
}


int main() {
    int v, e, f, t;
    cin >> v >> e;

    vector<vector<int> > graph(v + 1);
    vector<bool> used(v + 1, false);
    vector<int> result;

    for (size_t i = 0; i < e; ++i) {
        cin >> f >> t;
        graph[f].push_back(t);
    }

    cin >> v;

    dfs(graph, v, used, result);

    for (size_t i = result.size(); i > 0; --i) {
        cout << result[i - 1] << ' ';
    }
    cout << endl;

    return 0;
}
