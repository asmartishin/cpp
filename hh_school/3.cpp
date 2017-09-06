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

vector<int> numberToArray(int number) {
    int n = 0;
    vector<int> v(10, 0);
    string s = to_string(number);

    for (size_t i = 0; i < s.size(); ++i) {
        n = s[i] - '0';
        ++v[n];
    }

    return v;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.precision(10);

    int result = 0;

    for (size_t i  = 1; i < 1e9; ++i) {
        vector<int> number = numberToArray(i);
        vector<int> number2 = numberToArray(i * 2);
        vector<int> number3 = numberToArray(i * 3);

        if (number == number2 && number2 == number3) {
            result = i;
            break;
        }
    }

    cout << result << endl;

    return 0;
}
