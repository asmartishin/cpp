#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {
    int n, m, black_count = 0, result = 0, max_x = -1e9, min_x = 1e9, max_y = -1e9, min_y = 1e9;
    cin >> n >> m;
    pair<int, int> max_element;
    bool not_square = false;

    vector<vector<char> > v(n, vector<char>(m));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> v[i][j];
            if (v[i][j] == 'B') {
                ++black_count;
                max_x = max(max_x, i);
                min_x = min(min_x, i);
                max_y = max(max_y, j);
                min_y = min(min_y, j);
            }
        }
    }

    if (black_count == 0) {
        cout << 1 << endl;
        return 0;
    }

    int square_size = max(max_x - min_x + 1, max_y - min_y + 1);

    for (size_t i = min_x; i <= max_x; ++i) {
        for (size_t j = min_y; j <= max_y; ++j) {
            if (v[i][j] == 'W') {
                ++result;
            }
        }
    }

    if (square_size == (max_x - min_x + 1)) {
        int delta = square_size - (max_y - min_y + 1);
        int delta2 = min_y + (m - max_y - 1);
        if (delta2 >= delta) {
            result += delta * square_size;
        } else {
            not_square = true;
        }
    } else {
        int delta = square_size - (max_x - min_x + 1);
        int delta2 = min_x + (n - max_x - 1);
        if (delta2 >= delta) {
            result += delta * square_size;
        } else {
            not_square = true;
        }
    }

    if (!not_square) {
        cout << result << endl;
    } else {
        cout << -1 << endl;
    }

    return 0;
}
