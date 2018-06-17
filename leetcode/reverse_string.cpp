#include <iostream>

using namespace std;


int main() {
    string s = "hello";

    int l = 0, r = s.size() - 1;

    while (l < r)
        swap(s[l++], s[r--]);

    cout << s << endl;
    return 0;
}
