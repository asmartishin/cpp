#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


struct Segment {
    int start, end;

    bool operator<(const Segment& other) const {
        return start < other.start;
    }
};


int main() {
    int n, t = 0;
    long long s, e;
    bool f = true;

    cin >> n;

    vector<pair<long long, int> > v;

    for (size_t i = 0; i < n; ++i) {
        cin >> s >> e;
        v.push_back(make_pair(s, 1));
        v.push_back(make_pair(e + 1, -1));
    }

    sort(v.begin(), v.end());

    for (size_t i = 0; i < v.size(); ++i) {
        t += v[i].second;
        if (t > 2) {
            f = false;
        }
    }

    if (f) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
