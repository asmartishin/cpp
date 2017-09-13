#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;


int main() {
    int n;
    cin >> n;

    vector<int> a(2 * n);

    for (size_t i = 0; i < 2 * n; ++i) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    if (a[n] > a[n - 1]) {
        cout << "YES";
    } else {
        cout << "NO";
    }

    return 0;
}
