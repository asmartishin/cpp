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

    int n, watcher = 3, player1 = 1, player2 = 2, winner;
    cin >> n;

    for (size_t i = 0; i < n; ++i) {
        cin >> winner;
        if (winner == watcher) {
            cout << "NO" << endl;
            return 0;
        } else if (winner == player1)
            swap(watcher, player2);
        else
            swap(watcher, player1);
    }

    cout << "YES" << endl;

    return 0;
}
