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


void populateMatrix(vector<vector<int> > &matrix) {
    int size = matrix.size();

    int x = size / 2 + 1;
    int y = x - 1;

    matrix[y][x - 1] = 1;
    matrix[y][x] = 2;

    for (size_t i = 3; i < size * size + 1; ++i) {
        if (x - 1 >= 0 && y + 1 <= size - 1 && matrix[y][x - 1] && !matrix[y + 1][x]) {
            ++y;
            matrix[y][x] = i;
        } else if (x - 1 >= 0 && y - 1 >= 0 && matrix[y - 1][x] && !matrix[y][x - 1]) {
            --x;
            matrix[y][x] = i;
        } else if (x + 1 <= size - 1 && y - 1 >= 0 && matrix[y][x + 1] && !matrix[y - 1][x]) {
            --y;
            matrix[y][x] = i;
        } else if (x + 1 <= size - 1 && y + 1 <= size - 1 && matrix[y + 1][x] && !matrix[y][x + 1]) {
            ++x;
            matrix[y][x] = i;
        }
    }
}


long long diagonalSum(vector<vector<int> > &matrix) {
    long long result = 0;
    int size = matrix.size();

    for (size_t i = 0; i < size; ++i) {
        if (i != size - i - 1) {
            result += matrix[i][i];
            result += matrix[i][size - i - 1];
        } else {
            result += matrix[i][i];
        }
    }
    return result;
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.precision(10);

    int size = 1195;

    vector<vector<int> > matrix(size, vector<int>(size));

    populateMatrix(matrix);
    cout << diagonalSum(matrix) << endl;

    return 0;
}
