#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <cmath>

using namespace std;


int main() {
    long long barnSize = 0;
    long long seedIncome = 0;
    double daysCount = 0;

    cin >> barnSize;
    cin >> seedIncome;

    if (barnSize >= seedIncome) {
        daysCount = ceil(seedIncome + ((sqrt(1 + 8 * (barnSize - seedIncome)) - 1) / 2));
    } else if (barnSize > 1) {
        daysCount = ceil(((sqrt(1 + 8 * (barnSize + 1)) - 1) / 2));
    } else {
        daysCount = ceil(((sqrt(1 + 8 * (barnSize)) - 1) / 2));
    }

    cout << fixed << (long long)daysCount << endl;

    return 0;
}
