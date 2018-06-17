#include <iostream>
#include <unordered_map>
#include <limits>

using namespace std;


int main() {
    string s = "lloo";
    int index = numeric_limits<int>::max();

    unordered_map<char, pair<int, int> > m;

    for (size_t i = 0; i < s.size(); ++i) {
        ++m[s[i]].second;

        if (m[s[i]].first == 0)
            m[s[i]].first = i;
    }

    for (auto const&v: m) {
        if (v.second.second == 1)
            index = min(v.second.first, index);
    }

    if (index == numeric_limits<int>::max())
        index = -1;

    cout << index << endl;

    return 0;
}
