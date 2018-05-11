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

#define endl '\n'


int main() {
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.precision(10);

    string s1, s2;

    cin >> s1 >> s2;

    if (s1 == s2)
        cout << s1 << endl;
    else
        cout << 1 << endl;

    return 0;
}
