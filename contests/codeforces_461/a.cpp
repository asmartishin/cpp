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
    int x, y;
    bool result = true;

    cin >> x >> y;

    int originals = 1, copies = 0;

    if (y > originals) {
        copies = y - originals;
        if (x < copies || (x - copies) % 2)
            result = false;
    } else if ((y == originals && x > 0) || y < originals)
        result = false;

    if (result)
        cout << "YES";
    else
        cout << "NO";

    return 0;
}
