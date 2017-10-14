#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;


vector<int> SubarrayPredefinedSum(vector<int> v, int s) {
    vector<int> pv(v.size() + 1);
    int sum = 0;
    unordered_map<int, int> m;

    m[0] = 0;

    for (size_t i = 0; i < v.size(); ++i) {
        sum += v[i];
        if (m.find(sum) == m.end())
            m[sum] = i + 1;
        pv[i + 1] = sum;
    }

    for (size_t i = 1; i <= pv.size(); ++i) {
        if (m.find(pv[i] - s) != m.end() && m[pv[i] - s] < i)
            return vector<int>(v.begin() + m[pv[i] - s], v.begin() + i);
    }

    return vector<int>(0);
}


int main() {
    int n, s;

    cin >> n >> s;

    vector<int> v(n);

    for (size_t i = 0; i < n; ++i)
        cin >> v[i];

    vector<int> result = SubarrayPredefinedSum(v, s);

    if (result.size() > 0) {
        for (size_t i = 0; i < result.size(); ++i)
            cout << result[i] << ' ';
        cout << endl;
    } else
        cout << -1;
}

