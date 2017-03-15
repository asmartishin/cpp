#include <iostream>
#include <cmath>

using namespace std;


int main() {
    long long barnSize = 0;
    long long seedIncome = 0;
    long long daysCount = 0;

    cin >> barnSize;
    cin >> seedIncome;

    if (barnSize >= seedIncome && barnSize > 1) {
        daysCount = (long long)ceil(seedIncome + ((sqrt((long double)(1 + 8 * (barnSize - seedIncome))) - 1) / 2));
    } else if (barnSize > 1) {
        daysCount = (long long)ceil(((sqrt((long double)(1 + 8 * (barnSize + 1))) - 1) / 2));
    } else {
        daysCount = 1;
    }

    cout << daysCount << endl;

    return 0;
}
