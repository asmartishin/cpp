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
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.precision(10);

    int MAX_CORD = 100;

    int n, q, c, x, y, s, t, x1, y1, x2, y2, result, brightness, amount;

    cin >> n >> q >> c;

    vector<vector<vector<int> > > points(c + 1, vector<vector<int> >(MAX_CORD + 1, vector<int>(MAX_CORD + 1)));

    for (size_t i = 0; i < n; ++i) {
        cin >> x >> y >> s;
        points[s][x][y]++;
    }

    for (size_t p = 0; p <= c; ++p) {
        for (size_t i = 1; i <= MAX_CORD; ++i) {
            for (size_t j = 1; j <= MAX_CORD; ++j) {
                points[p][i][j] += points[p][i - 1][j] + points[p][i][j - 1] - points[p][i - 1][j - 1];
            }
        }
    }

    for (size_t i = 0; i < q; ++i) {
        cin >> t >> x1 >> y1 >> x2 >> y2;
        result = 0;
        for (size_t p = 0; p <= c; ++p) {
            brightness = (p + t) % (c + 1);
            amount = points[p][x2][y2] - points[p][x1 - 1][y2] - points[p][x2][y1 - 1] + points[p][x1 - 1][y1 - 1];
            result += brightness * amount;
        }
        cout << result << endl;
    }

    return 0;
}
