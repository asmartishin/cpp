#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <climits>
#include <cassert>
#include <numeric>

using namespace std;

#define endl '\n'


bool divisible(string s) {
    int req_zeroes = 6;
    int req_ones = 1;
    bool found_one = false;

    for (size_t i = 0; i < s.size(); ++i) {
        if (s[i] == '0') {
            if (found_one)
                --req_zeroes;
        } else {
            found_one = true;
            --req_ones;
        }
    }

    if (req_ones > 0 || req_zeroes > 0)
        return false;

    return true;
}


string to_bit_unlim(int n) {
    string r = "";

    while(n) {
        if (n & 1)
            r += "1";
        else
            r += "0";
        n >>= 1;
    }

    reverse(r.begin(), r.end());
    return r;
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.precision(10);

//    for (size_t i = 1; i < 10000; ++i) {
//        if (!divisible(to_bit_unlim(64 * i))) {
//            cout << i << endl;
//        }
//    }

    string s;

    getline(cin, s);

    if (!divisible(s))
        cout << "no" << endl;
    else
        cout << "yes" << endl;

    return 0;
}
