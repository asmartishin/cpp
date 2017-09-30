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

char best_value(pair<char, char> p) {
    if (p.first == '+' || p.second == '+')
        return '+';
    else if (p.first == '0' || p.second == '0')
        return '0';
    else
        return '-';
}


pair<char, char> dfs(vector<vector<int> > &tree, vector<char> &values, vector<bool> &used, int n, int h, int k) {
    pair<int, int> result;

    used[n] = true;

    if (values[n] == '.') {
        set<char> c1;
        set<char> c2;
        for (size_t i = 0; i < tree[n].size(); ++i) {
            if (!used[tree[n][i]]) {
                result = dfs(tree, values, used, tree[n][i], h + 1, k);
                c1.insert(result.first);
                c2.insert(result.second);
            }
        }


        int i = 0;
        char r;
        for (auto &c: {c1, c2}) {
            if (c.find('-') != c.end())
                r = '+';
            else if (c.find('0') != c.end())
                r = '0';
            else
                r = '-';

            if (i == 0)
                result.first = r;
            else
                result.second = r;

            ++i;
        }

        if (h == k) {
            result.first = best_value(result);
            result.second = best_value(result);
        }

        return result;
    } else {
        if (values[n] == '-')
            return make_pair('+', '-');
        else if (values[n] == '0')
            return make_pair('0', '0');
        else
            return make_pair('-', '+');
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.precision(10);

    int n, k;

    cin >> n >> k;

    vector<char> values(n);
    vector<vector<int> > tree(n, vector<int>());

    for (size_t i = 0; i < n; ++i) {
        cin >> values[i];
    }

    for (size_t i = 0; i < n - 1; ++i) {
        int x, y;
        cin >> x >> y;

        tree[x - 1].push_back(y - 1);
        tree[y - 1].push_back(x - 1);
    }

    vector<bool> used(n, false);

    pair<char, char> result = dfs(tree, values, used,  0, 0, k);

    if (result.first == '+') {
        cout << "First" << endl;
    } else if (result.first == '-') {
        cout << "Second" << endl;
    } else {
        cout << "Draw" << endl;
    }

    return 0;
}
