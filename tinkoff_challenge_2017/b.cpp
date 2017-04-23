#include <iostream>
#include <vector>

using namespace std;


int n, m;
vector<vector<char> > town;


void print_town() {
    for (size_t i = 0; i != n; ++i) {
        for (size_t j = 0; j != m; ++j) {
            cout << town[i][j];
        }
        cout << endl;
    }
}

int find_path(int x, int y, int turns) {
    if (town[y][x] == 'T') {
        return true;
    }

    if (!(town[y][x] == 'S')) {
        town[y][x] = 'V';
    }

    if (x > 0 && (town[y][x - 1] == '.' || town[y][x - 1] == 'T')) {
        if (!((x < m && town[y][x + 1] == 'V') || town[y][x] == 'S' || (x < m && town[y][x + 1] == 'S'))) {
            if (turns == 2) {
                return false;
            } else if (find_path(x - 1, y, turns + 1)) {
                return true;
            }
        } else {
            if (find_path(x - 1, y, turns)) {
                return true;
            }
        }
    }

    if (x < m && (town[y][x + 1] == '.' || town[y][x + 1] == 'T')) {
        if (!((x > 0 && town[y][x - 1] == 'V') || town[y][x] == 'S' || (x > 0 && town[y][x - 1] == 'S'))) {
            if (turns == 2) {
                return false;
            } else if (find_path(x + 1, y, turns + 1)) {
                return true;
            }
        } else {
            if (find_path(x + 1, y, turns)) {
                return true;
            }
        }
    }

    if (y > 0 && (town[y - 1][x] == '.' || town[y - 1][x] == 'T')) {
        if (!((y < n && town[y + 1][x] == 'V') || town[y][x] == 'S' || (y < n && town[y + 1][x] == 'S'))) {
            if (turns == 2) {
                return false;
            } else if (find_path(x, y - 1, turns + 1)) {
                return true;
            }
        } else {
            if (find_path(x, y - 1, turns)) {
                return true;
            }
        }
    }

    if (y < n && (town[y + 1][x] == '.' || town[y + 1][x] == 'T')) {
        if (!((y > 0 && town[y - 1][x] == 'V') || town[y][x] == 'S' || (y > 0 && town[y - 1][x] == 'S'))) {
            if (turns == 2) {
                return false;
            } else if (find_path(x, y + 1, turns + 1)) {
                return true;
            }
        } else {
            if (find_path(x, y + 1, turns)) {
                return true;
            }
        }
    }

    town[y][x] = '.';

    return false;
}

int main() {
    int x_s, y_s;
    string row;

    cin >> n >> m;

    for (size_t i = 0; i != n; ++i) {
        cin >> row;
        town.push_back(vector<char>(row.begin(), row.end()));
    }

    for (size_t i = 0; i != n; ++i) {
        for (size_t j = 0; j != m; ++j) {
            if (town[i][j] == 'S') {
                x_s = j;
                y_s = i;
            }
        }
    }

    if (find_path(x_s, y_s, 0)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
