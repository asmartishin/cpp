#include <iostream>
#include <cassert>

using namespace std;


bool isPalindrome(const string &s) {
    assert(s.size() >= 1);

    int l = 0;
    int r = s.size() - 1;

    while (l < r) {
        while (!isalnum(s[l]))
            ++l;

        while (!isalnum(s[r]))
            --r;

        if (l >= r)
            break;

        if (tolower(s[l++]) != tolower(s[r--])) {
            return false;
        }
    }

    return true;
}


int main() {
    string s = " aa ";
    string result = "NO";

    if (isPalindrome(s))
        result = "YES";

    cout << result << endl;

    return 0;
}
