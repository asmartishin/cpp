#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


struct Point {
    int l;
    int r;
    int c;
    int len;

    Point(int l, int r, int c, int len) : l(l), r(r), c(c), len(len) {}
};


int main() {
    int n, x, c, r, l, len, cost;
    vector<vector<Point> > tours_len(200000);
    vector<Point> tours;
    int result = 1000000000;

    cin >> n >> x;

    for (size_t i = 0; i < n; ++i) {
        cin >> l >> r >> c;
        len = r - l + 1;
        tours_len[len].push_back(Point(l, r, c, len));
        tours.push_back(Point(l, r, c, len));
    }


    for (size_t i = 0; i < tours.size(); ++i) {
        cost = tours[i].c;
        for (size_t j = 0; j < tours_len[x - tours[i].len].size(); ++j) {
            if (tours_len[x - tours[i].len][j].l > tours[i].r) {
                cost += tours_len[x - tours[i].len][j].c;
                result = min(cost, result);
            }
        }
    }

    if (result == 1000000000) {
        cout << -1 << endl;
    } else {
        cout << result << endl;
    }

    return 0;
}
