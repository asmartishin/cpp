#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


int main() {
    vector<long long> enemiesPowers;
    long long enemyPower;
    long long enemiesCount;
    long positivePowers = 0;
    long negativePowers = 0;
    long long result = 0;
    long centerIndex;

    cin >> enemiesCount;

    for (size_t i = 0; i != enemiesCount; ++i) {
        cin >> enemyPower;
        enemiesPowers.push_back(enemyPower);
    }

    std::sort(enemiesPowers.begin(), enemiesPowers.end());

    for (size_t i = 0; i != enemiesPowers.size(); ++i) {
        if (enemiesPowers[i] < 0) {
            ++negativePowers;
        } else if (enemiesPowers[i] > 0) {
            ++positivePowers;
        }
    }

    if (negativePowers > positivePowers) {
        result = enemiesPowers[0];
        enemiesPowers.erase(enemiesPowers.begin());
    } else if (negativePowers < positivePowers) {
        result = enemiesPowers[enemiesPowers.size() - 1];
        enemiesPowers.erase(enemiesPowers.begin() + enemiesPowers.size() - 1);
    } else {
        centerIndex = enemiesPowers.size() / 2;
        result = enemiesPowers[centerIndex];
        enemiesPowers.erase(enemiesPowers.begin() + centerIndex);
    }

    for (size_t i = 0; i != enemiesPowers.size(); ++i) {
        cout << enemiesPowers[i] << ' ';
    }

    cout << result << endl;

    return 0;
}
