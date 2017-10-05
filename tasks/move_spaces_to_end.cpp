#include <iostream>
#include <string>

using namespace std;


void move_spaces_to_end(string &s) {
    size_t i = 0;
    for (size_t j = 0; j < s.size(); ++j) {
        if (s[j] != ' ')
            s[i++] = s[j];
    }

    while (i < s.size())
        s[i++] = ' ';
}


int main() {
    string s;
    getline(cin, s);

    move_spaces_to_end(s);
    cout << s << endl;

    return 0;
}
