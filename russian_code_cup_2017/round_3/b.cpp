#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void fightBoss(int n) {
    int h, a;
    pair<int, int> Boss;
    vector<pair<int, int> > Heroes(n);
    bool victory = false;
    int result = -1;

    cin >> h >> a;
    Boss = make_pair(h, a);

    for (size_t i = 0; i < n; ++i) {
        cin >> h >> a;
        Heroes[i] = make_pair(h, a);
    }

    sort(Heroes.begin(), Heroes.end(), [](pair<int, int> &left, pair<int, int> &right) {
        return left.first + left.second > right.first + right.second;
    });

    for (size_t i = 0; i < n; ++i) {
        while(Heroes[i].first > 0) {
            Boss.first -= Heroes[i].second;
            if (Boss.first <= 0) {
                victory = true;
                break;
            }
            Heroes[i].first -= Boss.second;
        }
        if (victory) {
            result = i;
            break;
        }
    }

    cout << result << endl;
}

int main() {
    int testsCount;
    long long n;
    cin >> testsCount;
    for (size_t i = 0; i != testsCount; ++i) {
        cin >> n;
        fightBoss(n);
    }
    return 0;
}
