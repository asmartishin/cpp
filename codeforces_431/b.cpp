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

bool comp_ids(vector<int> &ids, vector<int> &new_ids) {
    bool are_equal = true;
    sort(new_ids.begin(), new_ids.end());
    for (int i = 0; i < ids.size(); i++) {
        if (ids[i] != new_ids[i]) {
            are_equal = false;
            break;
        }
    }
    return are_equal;
}

int main() {
    ios::sync_with_stdio(false);
    cout.precision(10);

    bool result = false;
    int n, y;

    cin >> n;

    map<pair<double, double>, set<int> > lines;

    vector<pair<int, int> > points;
    set<int> ids;

    for (size_t i = 0; i < n; ++i) {
        cin >> y;
        points.push_back(make_pair(i, y));
        ids.insert(i);

        for (size_t j = 0; j < i; ++j) {
            int x1 = i;
            int y1 = y;

            int x2 = points[j].first;
            int y2 = points[j].second;

            int dy = y2 - y1;
            int dx = x2 - x1;
            double slope = (double)dy / dx;
            double intercept = y1 - slope * x1;

            lines[make_pair(intercept, abs(slope))].insert(i);
            lines[make_pair(intercept, abs(slope))].insert(j);
        }
    }

    for(auto it1 = lines.begin(); it1 != lines.end(); ++it1) {
        if (it1->second.size() == ids.size() - 1) {
            result = true;
            break;
        }
        for(auto it2 = it1; it2 != lines.end(); ++it2) {
            if (it1->first.first != it2->first.first && it1->first.second == it2->first.second) {
                it1->second.insert(it2->second.begin(), it2->second.end());
                if (ids == it1->second) {
                    result = true;
                    break;
                }
            }
        }
    }

    if (result) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}
