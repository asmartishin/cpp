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
#include <fstream>
#include <array>

using namespace std;

#define endl '\n'

array<pair<int, int>, 9> NEIGHBOURS{{
    {-1, -1},
    {-1, 0},
    {-1, 1},
    {0, 1},
    {0, 0},
    {0, -1},
    {1, 1},
    {1, 0},
    {1, -1},
}};


pair<int, int> nextDig(vector<vector<bool> > &orchard, int width, int height, int row, int col) {
    for (auto const &neighbourCoordinates: NEIGHBOURS) {
        int neighbourRow = row + neighbourCoordinates.first;
        int neighbourColumn =  col + neighbourCoordinates.second;

        if (orchard[neighbourRow][neighbourColumn] == false)
            return make_pair(row, col);
    }

    if (col == width) {
        col = 2;
        row += 3;
    } else if (col + 3 <= width)
        col += 3;
    else
        col = width;

    return make_pair(row, col);
}

void solve() {
    int a;
    cin >> a;

    vector<vector<bool> > orchard(1000, vector<bool>(1000, false));


    int height = 3;
    int width = 3;

    while (height * width < a) {
        if (height > width)
            ++width;
        else
            ++height;
    }

    int row = 2;
    int col = 2;

    int digRow;
    int digCol;

    while (true) {
        auto coordinates = nextDig(orchard, width, height, row, col);

        row = coordinates.first;
        col = coordinates.second;

        cout << row << ' ' << col << endl;
        cin >> digRow >> digCol;

        if (digRow == 0 && digCol == 0)
            break;

        else if (digRow == -1 && digCol == -1)
            exit(1);

        orchard[digRow][digCol] = true;
    }
}

int main() {
    int t;
    cin >> t;

    for (size_t i = 0; i < t; ++i) {
        solve();
    }

    return 0;
}
