#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;


int main() {
    int ls, lt;
    string s, t;

    vector<int> result;
    vector<int> tresult;

    cin >> ls >> lt;
    cin >> s >> t;

    for (size_t k = 0; k < ls; ++k) {
        result.push_back(k);
    }

    for (size_t i = 0; i < lt - ls + 1; ++i) {
        tresult.clear();
        for (size_t j = 0; j < ls; ++j) {
            if (t[i + j] != s[j]) {
                tresult.push_back(j);
            }
        }

        if (tresult.size() < result.size()) {
            result = tresult;
        }
    }

    cout << result.size() << endl;
    for (size_t i = 0; i < result.size(); ++i) {
        cout << result[i] + 1 << ' ';
    }
    cout << endl;
    return 0;
}
