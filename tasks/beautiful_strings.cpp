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
#include <climits>
#include <cassert>

using namespace std;

#define endl '\n'


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.precision(10);

    string s, result;
    getline(cin, s);

    bool startSentence = true;
    bool spaceMet = false;

    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == ' ') {
            if (startSentence)
                continue;
            else
                spaceMet = true;
        } else if (s[i] == '.') {
            if (startSentence) {
                cout << -1 << endl;
                return 0;
            } else {
                result += '.';
                if (i < s.size() - 1)
                    result += ' ';

                startSentence = true;
                spaceMet = false;
            }
        } else {
            if (startSentence) {
                result += toupper(s[i]);
                startSentence = false;
            } else {
                if (spaceMet)
                    result += ' ';

                result += tolower(s[i]);
                spaceMet = false;
            }
        }
    }

    if (result.back() == '.') {
        cout << result << endl;
    } else
        cout << -1 << endl;

    return 0;
}
