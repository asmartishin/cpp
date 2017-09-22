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

using namespace std;

#define endl '\n'


int cut_zeroes(int x) {
    while (x % 10 == 0) {
        x /= 10;
    }
    return x;
}


bool is_palindrome(int x) {
    int tx = x, rx = 0;

    while (tx > 0) {
        rx = rx * 10 + tx % 10;
        tx /= 10;
    }

    return rx == x;
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.precision(10);

    int x;

    cin >> x;

    if (is_palindrome(cut_zeroes(x)))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}
