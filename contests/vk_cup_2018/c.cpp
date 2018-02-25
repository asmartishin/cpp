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
#include <list>

using namespace std;


struct TPairHash {
    template<typename T1, typename T2>
    inline size_t operator()(const pair<T1, T2> &p) const {
        return hash<T1>()(p.first) ^ hash<T2>()(p.second);
    }
};


unordered_map<pair<string, int>, vector<pair<string, int> >, TPairHash> graph;
unordered_map<pair<string, int>, int, TPairHash> dest;
unordered_set<string> used_names;
unordered_set<pair<string, int>, TPairHash> visited;


pair<string, int> get_vertex() {
    int version, dep_count, dep_version;
    string name, dep_name;

    cin >> name >> version;
    pair<string, int> vertex = make_pair(name, version);

    cin >> dep_count;
    for (size_t j = 0; j < dep_count; ++j) {
        cin >> dep_name >> dep_version;
        pair<string, int> dep_vertex = make_pair(dep_name, dep_version);

        graph[vertex].push_back(dep_vertex);
    }

    return vertex;
}


set<pair<string, int> > bfs(pair<string, int>& first_vertex) {
    set<pair<string, int> > result;
    list<pair<string, int> > q;

    int current_dest = 0;

    q.push_back(first_vertex);
    dest[first_vertex] = 0;

    used_names.insert(first_vertex.first);

    while (!q.empty()) {
        auto vertex = q.front();

        if (dest[vertex] > current_dest) {
            unordered_map<string, int> max_versions;
            list<pair<string, int> > qn;

            for (auto const &v: q) {
                if (v.second > max_versions[v.first])
                    max_versions[v.first] = v.second;
            }

            for (auto const &v: q) {
                if (v.second == max_versions[v.first]) {
                    if (used_names.find(v.first) == used_names.end()) {
                        qn.push_back(v);
                        result.insert(v);
                        used_names.insert(v.first);
                    }
                }
            }
            current_dest += 1;

            q = qn;
        }

        if (!q.empty()) {
            vertex = q.front();
            q.pop_front();

            for (size_t i = 0; i < graph[vertex].size(); ++i) {
                auto &dep_vertex = graph[vertex][i];
                if (visited.find(dep_vertex) == visited.end()) {
                    dest[dep_vertex] = current_dest + 1;
                    visited.insert(dep_vertex);
                    q.push_back(dep_vertex);
                }
            }
        }
    }
    return result;
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.precision(10);

    int n;
    cin >> n;

    auto first_vertex = get_vertex();

    for (size_t i = 1; i < n; ++i) {
        get_vertex();
    }

    auto result = bfs(first_vertex);
    cout << result.size() << endl;

    for (auto const &v: result)
        cout << v.first << ' ' << v.second << endl;

    return 0;
}
