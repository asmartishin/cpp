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

    int n, k;

    cin >> n >> k;

    int availableCells = 2 * (n - 2);

    vector<vector<char> > field(4, vector<char>(n, '.'));

    if (k > availableCells) {
        cout << "NO" << endl;
        return 0;
    }

    if (k % 2 == 0) {
        for (size_t i = 0; i < k / 2; ++i) {
            field[1][i + 1] = '#';
            field[2][i + 1] = '#';
        }
    } else {
        field[1][n / 2] = '#';

        int cellsOnLeftSide = (k - 1) / 2;
        int cellsOnRightSide = (k - 1) / 2;

        if (cellsOnRightSide > 0) {
            for (size_t i = 0; i < n / 2; ++i) {
                field[1][i + 1] = '#';
                if (--cellsOnLeftSide > 0)
                    field[2][i + 1] = '#';

                if (--cellsOnLeftSide <= 0)
                    break;
            }

            for (size_t i = n - 1; i > n / 2; --i) {
                field[1][i - 1] = '#';

                if (--cellsOnRightSide > 0)
                    field[2][i - 1] = '#';

                if (--cellsOnRightSide <= 0)
                    break;
            }
        }
    }

    cout << "YES" << endl;

    for (const auto &row: field) {
        for (const auto &cell: row)
            cout << cell;
        cout << endl;
    }

    return 0;
}
