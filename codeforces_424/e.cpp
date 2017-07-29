#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;


int main() {
    int n, t;
    cin >> n;
    vector<int> v(n);
    queue<int> q;

    for (size_t i = 0; i <  n; ++i) {
        cin >> t;
        q.push(t);
        v[i] = t;
    }

    sort(v.begin(), v.end());

    int i = 0, j = 0;

    while (!q.empty()) {
        t = q.front();
        q.pop();
        if (t == v[i]) {
            ++i;
        } else {
            q.push(t);
        }
        ++j;
    }

    cout  << j << endl;

    return 0;
}
