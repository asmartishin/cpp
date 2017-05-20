#include <iostream>
#include <vector>
#include <map>

using namespace std;


int main() {
    string s;
    vector<char> v;
    map<char, int> ob = {{'{', 1}, {'[', 2}, {'(', 3}};
    map<int, char> cb = {{1, '}'}, {2, ']'}, {3, ')'}};

    cin >> s;

    for (size_t i = 0; i < s.size(); ++i) {
        if (ob[s[i]]) {
            v.push_back(ob[s[i]]);
        } else {
            if (!v.empty() && cb[v.back()] == s[i]) {
                v.pop_back();
            } else {
                cout << i << endl;
                return 0;
            }
        }
    }

    if (v.empty()) {
        cout << "CORRECT" << endl;
    } else {
        cout << v.size() << endl;
    }

    return 0;
}
