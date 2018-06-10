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
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.precision(10);

    int n;
    string s;
    cin >> n >> s;

    auto zeroesCount = count(s.begin(), s.end(), '0');
    auto onesCount = count(s.begin(), s.end(), '1');

    if (onesCount > 0)
        cout << '1';
    for (size_t i = 0; i < zeroesCount; ++i)
        cout << '0';

    cout << endl;

    return 0;
}
