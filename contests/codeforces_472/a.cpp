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

enum Colors {
    Cian = 0,
    Magenta = 1,
    Yellow = 2,
    Undefined = 3,
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.precision(10);

    int n;
    char ch;
    vector<Colors> colors;

    cin >> n;

    vector<vector<int> > coloring(3, vector<int>(n));

    for (size_t i = 0; i < n; ++i) {
        cin >> ch;
        if (ch == 'C')
            colors.push_back(Colors::Cian);
        else if (ch == 'M')
            colors.push_back(Colors::Magenta);
        else if (ch == 'Y')
            colors.push_back(Colors::Yellow);
        else
            colors.push_back(Colors::Undefined);
    }

    if (n == 1 && colors[0] == Undefined) {
        cout << "Yes" << endl;
        return 0;
    }

    if (colors[0] == Cian) {
        coloring[0][0] = 1;
        coloring[1][0] = 0;
        coloring[2][0] = 0;
    } else if (colors[0] == Magenta) {
        coloring[0][0] = 0;
        coloring[1][0] = 1;
        coloring[2][0] = 0;
    } else if (colors[0] == Yellow) {
        coloring[0][0] = 0;
        coloring[1][0] = 0;
        coloring[2][0] = 1;
    } else {
        coloring[0][0] = 1;
        coloring[1][0] = 1;
        coloring[2][0] = 1;
    }

    for (size_t i = 1; i < n; ++i) {
        if (colors[i] == Cian) {
            coloring[0][i] = min(coloring[1][i-1] + coloring[2][i-1], 2);
            coloring[1][i] = 0;
            coloring[2][i] = 0;
        } else if (colors[i] == Magenta) {
            coloring[0][i] = 0;
            coloring[1][i] = min(coloring[0][i-1] + coloring[2][i-1], 2);
            coloring[2][i] = 0;
        } else if (colors[i] == Yellow) {
            coloring[0][i] = 0;
            coloring[1][i] = 0;
            coloring[2][i] = min(coloring[0][i-1] + coloring[1][i-1], 2);
        } else {
            coloring[0][i] = min(coloring[1][i-1] + coloring[2][i-1], 2);
            coloring[1][i] = min(coloring[0][i-1] + coloring[2][i-1], 2);
            coloring[2][i] = min(coloring[0][i-1] + coloring[1][i-1], 2);
        }
    }
//
//    for (auto const &r: coloring) {
//        for (auto const &el: r)
//            cout << el << ' ';
//        cout << endl;
//    }

    if (colors.back() == Undefined) {
        for (size_t i = 0; i < 3; ++i) {
            if (coloring[i][n - 1] == 1) {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }


    for (size_t i = 0; i < 3; ++i) {
        if (coloring[i][n - 1] == 2) {
            cout << "Yes" << endl;
            return 0;
        }
    }

    cout << "No" << endl;

    return 0;
}
