#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;


int distance(vector<vector<int> > &adj, int s, int t) {
    int n = adj.size();
    vector<int> dist(n, numeric_limits<int>::max());
    queue<int> q;

    dist[s] = 0;
    q.push(s);

    while (!q.empty()) {
        int v = q.front();
        q.pop();

        for (size_t i = 0; i < adj[v].size(); ++i) {
            int nv = adj[v][i];
            if (dist[nv] == numeric_limits<int>::max()) {
                q.push(nv);
                dist[nv] = dist[v] + 1;
            }
        }
    }

    if (dist[t] != numeric_limits<int>::max()) {
        return dist[t];
    }

    return -1;
}

int main() {
    int n, m;
    std::cin >> n >> m;
    vector<vector<int> > adj(n, vector<int>());
    for (int i = 0; i < m; i++) {
        int x, y;
        std::cin >> x >> y;
        adj[x - 1].push_back(y - 1);
        adj[y - 1].push_back(x - 1);
    }
    int s, t;
    std::cin >> s >> t;
    s--, t--;
    std::cout << distance(adj, s, t);
}
