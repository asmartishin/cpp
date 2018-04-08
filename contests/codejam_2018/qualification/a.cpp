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
#include <fstream>

using namespace std;

#define endl '\n'


int getDamage(string &p) {
    int damage = 0;
    int currentPower = 1;

    for (const auto &v: p) {
        if (v == 'S')
            damage += currentPower;
        else
            currentPower *= 2;
    }

    return damage;
}

void bestPermutation(string &p) {
    auto currentDamage = getDamage(p);
    pair<int, int> indices;

    for (size_t i = 0; i < p.size() - 1; ++i) {
        swap(p[i], p[i + 1]);
        if (getDamage(p) < currentDamage)
            indices = make_pair(i, i + 1);
        swap(p[i], p[i + 1]);
    }

    swap(p[indices.first], p[indices.second]);
}


int solve(int d, string &p) {
    if (count(p.begin(), p.end(), 'S') > d)
        return -1;

    int hacks = 0;

    while (getDamage(p) > d) {
        bestPermutation(p);
        ++hacks;
    }

    return hacks;
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.precision(10);

    int t, d;
    string p;

    cin >> t;

    for (size_t i = 0; i < t; ++i) {
        cin >> d;
        getline(cin, p);

        p.erase(remove(p.begin(), p.end(), ' '), p.end());

        auto hacks = solve(d, p);

        cout << "Case #" << i + 1 << ": ";
        if (hacks == -1)
            cout << "IMPOSSIBLE";
        else
            cout << hacks;
        cout << endl;
    }

    return 0;
}
