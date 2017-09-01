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


bool is_even(int a) {
    return a % 2 == 0;
}

int main() {
    ios::sync_with_stdio(false);
    cout.precision(10);

    bool result = true;

    int n;

    cin >> n;

    vector<int> a(n);

    for (size_t i = 0; i < n; ++i) {
        cin >> a[i];
    }

    if (is_even(a[0]) || is_even(a[n - 1]) || is_even(n)) {
        result = false;
    }

    if (result) {
        cout << "Yes";
    } else {
        cout << "No";
    }


    return 0;
}
