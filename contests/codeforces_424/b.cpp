#include <iostream>
#include <vector>
#include <locale>

using namespace std;


int main() {
    vector<char> r1(26);
    vector<char> r2(26);
    string s;
    bool upper = false;
    bool inserted = false;
    string result = "";
    char t;

    for (size_t i = 0; i < 26; ++i) {
        cin >> r1[i];
    }
    for (size_t i = 0; i < 26; ++i) {
        cin >> r2[i];
    }

    cin >> s;

    for (size_t i = 0; i < s.size(); ++i) {
        t = s[i];
        if (isupper(t)) {
            upper = true;
            t = tolower(t);
        }

        for (size_t j = 0; j < 26; ++j) {
            if (r1[j] == t) {
                if (upper) {
                    result += toupper(r2[j]);
                } else {
                    result += r2[j];
                }
                inserted = true;
                break;
            }
        }
        if (!inserted) {
            result += s[i];
        }
        inserted = false;
        upper = false;
    }

    cout << result << endl;
    return 0;
}
