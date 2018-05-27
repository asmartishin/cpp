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

    string s;
    getline(cin, s);
    int linksCount = 0;
    int pearlsCount = 0;


    for (const auto &v: s) {
        if (v == '-')
            ++linksCount;
        else
            ++pearlsCount;
    }

    if (pearlsCount == 0 || linksCount % pearlsCount == 0)
        cout << "YES";
    else
        cout << "NO";

    return 0;
}
