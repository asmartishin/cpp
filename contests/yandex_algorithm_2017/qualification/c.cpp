#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;


int main() {
    int n, lens, result = 0;
    cin >> n;

    vector<int> orders(n);
    map<int, bool> lenses;


    for (size_t i = 0; i < n; ++i) {
        cin >> lens;
        orders[i] = lens;
    }

    sort(orders.begin(), orders.end());

    int end = orders.size() / 2;
    int start = end - 1;

    while (start >= 0 || end <= orders.size() - 1) {
        if (start >= 0) {
            if (lenses.find(orders[start]) != lenses.end()) {
                lenses.erase(orders[start]);
            } else if (lenses.find(orders[start] + 1) != lenses.end()) {
                lenses.erase(orders[start + 1]);
            } else {
                lenses[orders[end]] = true;
            }
            --start;
            ++result;
        }
        if (end <= orders.size() - 1) {
            if (lenses.find(orders[start]) != lenses.end()) {
                lenses.erase(orders[start]);
            } else if (lenses.find(orders[start] - 1) != lenses.end()) {
                lenses.erase(orders[start - 1]);
            } else {
                lenses[orders[end]] = true;
            }
            ++end;
            ++result;
        }
    }

    cout << result << endl;

    return 0;
}
