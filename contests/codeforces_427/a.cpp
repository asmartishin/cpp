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

using namespace std;

#define endl '\n'


int main() {
    ios::sync_with_stdio(false);
    cout.precision(10);

    int s, v1, v2, t1, t2;

    cin >> s >> v1 >> v2 >> t1 >> t2;

    int r1 = 2 * t1 + s * v1;
    int r2 = 2 * t2 + s * v2;

    if (r1 < r2) {
        cout << "First" << endl;
    } else if (r1 > r2) {
        cout << "Second" << endl;
    } else {
        cout << "Friendship" << endl;
    }

    return 0;
}
