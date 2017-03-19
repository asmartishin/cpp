#include <iostream>
#include <vector>

using namespace std;

// 1 - red
// 2 - blue
// 3 - black
// 4 - yellow
// 5 - pink


int main() {
    vector<pair<bool, bool> >seats;
    long long rowsCount;
    long long passengersCount;
    long long row;
    int position;
    vector<vector<long long> > result(5);

    cin >> rowsCount >> passengersCount;

    long long minAvailableRow = 1;
    long long maxAvailableRow = rowsCount;
    long long centerRow = rowsCount / 2;

    for (size_t i = 0; i != rowsCount; ++i) {
        seats.push_back(make_pair(false, false));
    }

    for (size_t i = 0; i != passengersCount; ++i) {
        cin >> row >> position;

        if (row == minAvailableRow) {
            //red
            if (position == 1) {
                result[0].push_back(i + 1);
            } else if (position == 2 && seats[row].first) {
                result[0].push_back(i + 1);
            }
            //blue
            if (position == 2) {
                result[1].push_back(i + 1);
            } else if (position == 1 && seats[row].second) {
                result[1].push_back(i + 1);
            }
        } else if (row == maxAvailableRow) {
            //black
            if (position == 1) {
                result[2].push_back(i + 1);
            } else if (position == 2 && seats[row].first) {
                result[2].push_back(i + 1);
            }
            //blue
            if (position == 2) {
                result[3].push_back(i + 1);
            } else if (position == 1 && seats[row].second) {
                result[3].push_back(i + 1);
            }
        }
        result[4].push_back(i + 1);
        if (position == 1) {
            seats[row].first = true;
        } else {
            seats[row].second = true;
        }
        if (seats[row].second && seats[row].first) {
            if (row <= centerRow) {
                minAvailableRow = row + 1;
                if (seats[row + 1].second && seats[row + 1].first) {
                    for (size_t i = row; i != centerRow; ++i) {
                        if (seats[i].second && seats[i].first) {
                            minAvailableRow = i;
                        } else {
                            break;
                        }
                    }
                }
            } else if (row > centerRow) {
                minAvailableRow = row - 1;
                if (seats[row - 1].second && seats[row - 1].first) {
                    for (size_t i = row; i != centerRow; --i) {
                        if (seats[i].second && seats[i].first) {
                            minAvailableRow = i;
                        } else {
                            break;
                        }
                    }
                }
            }
        }
    }

    for (size_t i = 0; i != result.size(); ++i) {
        cout << result[i].size() << ' ';
        for (size_t j = 0; j != result[i].size(); ++j) {
            cout << result[i][j] << ' ';
        }
        cout << endl;
    }

    return 0;
}
