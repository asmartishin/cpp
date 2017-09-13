#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {
    long long n, k, stock;
    long long result = 0;

    cin >> n >> k;

    vector<long long> stocks (n);

    for (size_t i = 0; i < n; ++i) {
        cin >> stock;
        stocks[i] = stock;
    }

    long long remainder = stocks[0] % k;

    long long min_stock = *min_element(stocks.begin(), stocks.end());

    for (size_t i = 0; i < n; ++i) {
        if (stocks[i] % k == remainder && stocks[i] != min_stock) {
            result += (stocks[i] - min_stock) / k;
        } else if (stocks[i] % k != remainder) {
            cout << "-1" << endl;
            return 0;
        }
    }

    cout << result << endl;

    return 0;
}
