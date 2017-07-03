#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;


int main() {
    int ls, lt, ti;
    string s, t;

    vector<int> result;
    vector<int> tresult;

    bool found = false;

    cin >> ls >> lt;
    cin >> s >> t;

    int tcount = ls, result_count = ls;

    for (size_t k = 0; k < ls; ++k) {
        result.push_back(k);
    }

    for (size_t i = 0; i < lt; ++i) {
        ti = i;
        for (size_t j = 0; j < ls; ++j) {
            if (t[i] != s[j]) {
                if (found) {
                    tcount += 1;
                    tresult.push_back(j);
                }
            } else {
                if (!found) {
                    tcount = j;
                    found = true;
                    tresult.clear();
                    for (size_t k = 0; k < j; ++k) {
                        tresult.push_back(k);
                    }
                }
            }
            if (found) {
                ++i;
            }
        }
        i = ti;
        found = false;
        if (tcount < result_count) {
            result_count = tcount;
            result = tresult;
        }
    }

    cout << result_count << endl;
    for (size_t i = 0; i < result.size(); ++i) {
        cout << result[i] + 1 << ' ';
    }
    cout << endl;
    return 0;
}
