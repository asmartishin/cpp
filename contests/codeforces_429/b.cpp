#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;


int main() {
    int n, v, even = 0, not_even = 0;
    string s;
    ios::sync_with_stdio(false);

    cin >> n;
//    getline(cin, s);
//    getline(cin, s);
//
//    stringstream ss(s);

    for (size_t i = 0; i < n; ++i) {
        cin >> v;
        if (v % 2 == 0) {
            ++even;
        } else {
            ++not_even;
        }
    }

    if (not_even >= 1) {
        cout << "First" << endl;
    } else {
        cout << "Second" << endl;
    }

    return 0;
}
