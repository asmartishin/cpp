#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <limits>
#include <cassert>
#include <numeric>

using namespace std;

#define endl '\n'


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.precision(10);

    vector<string> n{"Danil", "Olya", "Slava", "Ann", "Nikita"};
    int found = 0;
    string s;
    getline(cin, s);

    if (s.size() == 0) {
        cout << "NO" << endl;
        return 0;
    }

    for (size_t i = 0; i < n.size(); ++i) {
        if (s.size() >= n[i].size()) {
            for (size_t j = 0; j < s.size() - n[i].size() + 1; ++j) {
                for (size_t k = 0; k < n[i].size(); ++k) {
                    if (n[i][k] != s[j + k])
                        break;
                    if (k == n[i].size() - 1) {
                        ++found;
                    }
                }
            }
        }
    }

    if (found == 1)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}
