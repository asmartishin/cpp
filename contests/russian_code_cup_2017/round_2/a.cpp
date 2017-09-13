#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void arrangeSeats(int n, int m) {
    vector<vector<int>> seats(n, vector<int>(m));
    vector<int> weights;
    int currentWeight = 0;
    vector< pair<int, int> > pointsQueue;
    pair<int, int> point;

    for (size_t i = n * m; i != 0; --i) {
        weights.push_back(i);
    }
    seats[0][0] = weights[0];

    if (n >= 1 && m >= 1) {
        if (m > 1) {
            pointsQueue.push_back(make_pair(0, 1));
        }
        if (n > 1) {
            pointsQueue.push_back(make_pair(1, 0));
        }

        while (!pointsQueue.empty()) {
            point = pointsQueue.front();
            pointsQueue.erase(pointsQueue.begin());
            seats[point.first][point.second] = weights[++currentWeight];
            if (point.second + 1 < m && seats[point.first][point.second + 1] == 0) {
                if (find(pointsQueue.begin(), pointsQueue.end(), make_pair(point.first, point.second + 1)) == pointsQueue.end()) {
                    pointsQueue.push_back(make_pair(point.first, point.second + 1));
                }
            }
            if (point.first + 1 < n && seats[point.first + 1][point.second] == 0) {
                if (find(pointsQueue.begin(), pointsQueue.end(), make_pair(point.first + 1, point.second)) == pointsQueue.end()) {
                    pointsQueue.push_back(make_pair(point.first + 1, point.second));
                }
            }
        }
    }

    for (size_t i = 0; i != n; ++i) {
        for (size_t j = 0; j != m; ++j) {
            cout << seats[i][j] << ' ';
        }
        cout << endl;
    }
}

int main() {
    int testsCount;
    int n, m;
    cin >> testsCount;
    for (size_t i = 0; i != testsCount; ++i) {
        cin >> n >> m;
        arrangeSeats(n, m);
    }
    return 0;
}
