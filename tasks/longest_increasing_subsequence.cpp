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


int findMax(vector<int> tree, int index, int left, int right, int query_start, int query_end) {
    if (left >= query_start && right <= query_end)
        return tree[index];

    if (left > query_end || right < query_start) {
        return 0;
    }

    int middle = (left + right) / 2;

    return max(
        findMax(tree, 2 * index + 1, left, middle, query_start, query_end),
        findMax(tree, 2 * index + 2, middle + 1, right, query_start, query_end)
    );
}


void buildTree(vector<int> &tree, int index,  int left, int right, int origin_index, int origin_value) {
    if (origin_index < left || origin_index > right)
        return;

    if (left == right) {
        tree[index] = origin_value;
        return;
    }

    int middle = (left + right) / 2;

    buildTree(tree, 2 * index + 1, left, middle, origin_index, origin_value);
    buildTree(tree, 2 * index + 2, middle + 1, right, origin_index, origin_value);

    tree[index] = max(tree[2 * index + 1], tree[2 * index + 2]);
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.precision(10);

    int n;

    cin >> n;

    vector<pair<int, int> > pairs(n);


    for (size_t i = 0; i < n; ++i) {
        cin >> pairs[i].first;
        pairs[i].second = i;
    }

    sort(pairs.begin(), pairs.end(), [](const pair<int, int> &l, const pair<int, int> &r) {
        return (l.first == r.first) ? (l.second > r.second) : (l.first < r.first);
    });

    int size = pow(2, (int)(ceil(sqrt(n))) + 1) - 1;
    vector<int> tree(size, 0);

    for (size_t i = 0; i < n; ++i) {
        buildTree(tree, 0, 0, n - 1, pairs[i].second, findMax(tree, 0, 0, n - 1, 0, pairs[i].second) + 1);
    }

    cout << tree[0] << endl;

    return 0;
}
