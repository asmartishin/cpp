#include <iostream>
#include <vector>

using namespace std;


int uniquePaths(int m, int n) {
    vector<vector<int> > states(m, vector<int>(n));

    for (size_t i = 0; i < m; ++i)
        states[i][0] = 1;

    for (size_t i = 0; i < n; ++i)
        states[0][i] = 1;

    for (size_t i = 1; i < m; ++i) {
        for (size_t j = 1; j < n; ++j) {
            states[i][j] = states[i - 1][j] + states[i][j - 1];
        }
    }

    return states[m - 1][n - 1];
}


int main() {
    int m = 2, n = 3;

    cout << uniquePaths(m, n) << endl;
    return 0;
}
