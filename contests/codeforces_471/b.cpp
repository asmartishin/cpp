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


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.precision(10);

    string s;
    getline(cin, s);

    unordered_map<char, int> chars;

    for (auto const &v: s) {
        chars[v] += 1;
    }

    int n = chars.size();
    bool result = false;

    vector<int> counts(n);
    for(auto const &v: chars) {
        counts.push_back(move(v.second));
    }

    sort(counts.begin(), counts.end(), std::greater<>());

    if (n == 4)
        result = true;
    else if (n == 3 &&  counts[0] >= 2)
        result = true;
    else if (n == 2 && counts[0] >= 2 && counts[1] >= 2)
        result = true;

    if (result)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    return 0;
}
