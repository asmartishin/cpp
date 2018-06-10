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
#include <limits>
#include <cassert>
#include <fstream>
#include <array>

using namespace std;

#define endl '\n'

struct Segment {
    int Start;
    int End;
    size_t Id;

    bool operator <(const Segment &other) const {
        return (Start < other.Start) || (Start == other.Start && End > other.End);
    }
};

int main() {
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.precision(10);

    int n, l ,r;
    cin >> n;

    vector<Segment> segments;

    for (size_t i = 0; i < n; ++i) {
        cin >> l >> r;
        segments.push_back(Segment{l, r, i + 1});
    }

    sort(begin(segments), end(segments));

    size_t previousSegment = 0;

    for (size_t i = 1; i < n; ++i) {
        if (segments[previousSegment].Start <= segments[i].Start && segments[previousSegment].End >= segments[i].End) {
            cout << segments[i].Id  << ' ' << segments[previousSegment].Id  << endl;
            return 0;
        } else {
            previousSegment = i;
        }
    }

    cout << -1 << ' ' << -1 << endl;

    return 0;
}
