#include <iostream>
#include <string>

using namespace std;


void move_spaces_to_end(string &s) {
    size_t j = 0;
    for (size_t i = 0; i < s.size(); ++i) {
        if (s[i] == ' ') {
            while (s[j] == ' ' && j < s.size())
                ++j;
            swap(s[i], s[j]);
        }
        ++j;
    }
}

int main() {
    string s;
    getline(cin, s);

    move_spaces_to_end(s);
    cout << s << endl;

    return 0;
}
