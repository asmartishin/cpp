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

using std::cout;
using std::cin;
using std::string;
using std::vector;

#define endl '\n'


int main() {
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.precision(10);

    string s;
    int n = 0;

    std::getline(cin, s);

    int numberOfPluses = 1;
    int numberOfMinuses = 0;
    vector<std::pair<bool, int> > vars{std::make_pair(true, 0)};

    for (size_t i = 0; i < s.size(); ++i) {
        if (s[i] == '-') {
            vars.push_back(std::make_pair(false, 0));
            ++numberOfMinuses;
        } else if (s[i] == '+') {
            vars.push_back(std::make_pair(true, 0));
            ++numberOfPluses;
        } else if (isdigit(s[i])) {
            n *= 10;
            n += s[i] - '0';
        }
    }

    int diff = numberOfPluses - numberOfMinuses;

    for (auto &v: vars) {
        if (v.first) {
            --diff;
            v.second = std::min(n, std::max(n - diff, 1));
            diff += v.second;
        } else {
            ++diff;
            v.second = std::min(n, std::max(diff - n, 1));
            diff -= v.second;
        }
    }

    if (diff != n) {
        cout << "Impossible";
        return 0;
    }

    cout << "Possible" << endl;
    cout << vars[0].second;

    for (size_t i = 1; i < vars.size(); ++i)
        cout << ' ' << (vars[i].first ? '+' : '-') << ' ' << vars[i].second;
    cout << " = " << n << endl;

    return 0;
}
