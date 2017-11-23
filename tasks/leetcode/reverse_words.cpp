#include <iostream>

using namespace std;


void reverseWords(string &s) {
    int l = 0;
    int r = 0;

    while (r < s.size()) {
        while (r < s.size() && s[r] == ' ')
            ++r;

        while (r < s.size() && s[r] != ' ')
            swap(s[l++], s[r++]);
        s[l++] = ' ';
    }

    for (int i = s.size() - 1; i >= 0; --i) {
        if (s[i] != ' ') {
            r = i;
            break;
        }
    }

    l = 0;
    s.resize(r + 1);

    while (l < r)
        swap(s[l++], s[r--]);

    l = 0;
    r = 0;
    int rw = 0;

    while (r < s.size()) {
        while (r < s.size() && s[r] != ' ')
            ++r;

        rw = r - 1;

        while (l < rw)
            swap(s[l++], s[rw--]);
        l = ++r;
    }
}


int main() {
    string s = "a";

    reverseWords(s);
    cout << s << endl;

    return 0;
}
