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
#include <climits>
#include <cassert>
#include <numeric>

using namespace std;

#define endl '\n'


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.precision(10);

    int n = 15;
    string line;

    for (size_t i = 1; i <= n; ++i) {
        line = "";
        if (i % 3 == 0)
            line += "Fizz";
        if (i % 5 == 0)
            line += "Buzz";
        if (line == "")
            line = to_string(i);
        cout << line << endl;
    }

    return 0;
}
