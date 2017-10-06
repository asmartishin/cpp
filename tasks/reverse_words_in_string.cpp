#include <iostream>
#include <string>

using namespace std;


int main() {
    string s;
    bool processing = false;
    getline(cin, s);

    int n = s.size();

    for (size_t i = 0; i < n / 2; ++i) {
        swap(s[i], s[n - 1 - i]);
    }

    size_t l = 0, r = 0;

    for (size_t i = 0; i < n; ++i) {
        if (s[i] == ' ' || i == n - 1) {
            if (processing) {
                if (s[i] != ' ')
                    r = i;
                else
                    r = i - 1;

                while (l < r)
                    swap(s[l++], s[r--]);
                processing = false;
            }
        } else if (!processing) {
            l = i;
            processing = true;
        }
    }

    cout << s << endl;

    return 0;
}
