#include <iostream>
#include <vector>

using namespace std;


int main() {
    string str;
    cin >> str;
    int matches = 0;

    vector<char> s(str.begin(), str.end());
    int sSize = s.size();
    bool replaced = false;

    for (int i = 0; i < sSize; ++i) {
        if (s[i] == 'V' && i + 1 < sSize) {
            if (s[i + 1] == 'K') {
                ++matches;
            } else if (s[i + 1] == 'V' && !replaced) {
                if (!(i + 2 < sSize && s[i + 2] == 'K')) {
                    ++matches;
                    replaced = true;
                }
            }
        } else if (s[i] == 'K' && i + 1 < sSize && s[i + 1] == 'K') {
            if (s[i + 1] == 'K' && !replaced) {
                if (!(i - 1 >= 0 && s[i - 1] == 'V')) {
                    ++matches;
                    replaced = true;
                }
            }
        }
    }

    cout << matches << endl;

    return 0;
}
