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


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.precision(10);

    int n;
    char c;
    string s, result;
    unordered_map<string, int> twoGrams;
    int maxOccurrences = 0;

    cin >> n;

    for (size_t i = 0; i < n; ++i) {
        cin >> c;
        s.push_back(c);
    }

    for (size_t i = 0; i < s.size() - 1; ++i) {
        ++twoGrams[string({s[i], s[i + 1]})];
    }

    for (const auto &v: twoGrams) {
        if (v.second > maxOccurrences) {
            result = v.first;
            maxOccurrences = v.second;
        }
    }

    cout << result << endl;

    return 0;
}
