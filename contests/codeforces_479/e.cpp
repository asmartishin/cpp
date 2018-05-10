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
#include <limits>
#include <cassert>
#include <fstream>
#include <array>

using namespace std;

#define endl '\n'


bool dfsFindCycle(vector<unordered_set<int> > &graph, set<int> &remainingVertices, int startVertex) {
    unordered_set<int> visitedVertices;
    stack<int> stackVertices;

    stackVertices.push(startVertex);

    while (!stackVertices.empty()) {
        auto currentVertex = stackVertices.top();
        stackVertices.pop();

        if (visitedVertices.find(currentVertex) != visitedVertices.end())
            continue;

        for (const auto &neighbourVertex: graph[currentVertex]) {
            stackVertices.push(neighbourVertex);
        }

        visitedVertices.insert(currentVertex);
        remainingVertices.erase(currentVertex);
    }

    for (const auto &vertex: visitedVertices) {
        if (graph[vertex].size() != 2)
            return false;
    }

    return true;
}

int countCycleComponents(vector<unordered_set<int> > &graph) {
    set<int> remainingVertices;
    int result = 0;

    for (size_t i = 0; i < graph.size(); ++i)
        remainingVertices.insert(i);

    while (!remainingVertices.empty()) {
        int startVertex = *remainingVertices.begin();
       if (dfsFindCycle(graph, remainingVertices, startVertex))
            ++result;
    }

    return result;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.precision(10);

    int n, m, v, u;

    cin >> n >> m;

    vector<unordered_set<int> > graph(n);

    for (size_t i = 0; i < m; ++i) {
        cin >> v >> u;
        --v;
        --u;
        graph[v].insert(u);
        graph[u].insert(v);
    }

    cout << countCycleComponents(graph) << endl;

    return 0;
}
