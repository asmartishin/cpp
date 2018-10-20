#include <vector>
#include <iostream>

using namespace std;

int main() {
    vector<pair<int, int>> v = {{2, 2}, {1, 2}, {2, 2}, {1, 1}};

    sort(begin(v), end(v), [](const pair<int, int>& lhs, const pair<int, int>& rhs){
        if (lhs.second == rhs.second) {
            return lhs.first < rhs.first;
        }

        return lhs.second < rhs.second;
    });

    for (const auto& el: v) {
        cout << el.first << ' ' << el.second << endl;
    }

    return 0;
}
