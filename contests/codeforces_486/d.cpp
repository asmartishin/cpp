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
#include <limits>
#include <cassert>
#include <fstream>
#include <array>

using namespace std;

#define endl '\n'

vector<long long> powers(int base, long long limit) {
    vector<long long> result;
    long long currentNumber = 1;

    while (currentNumber < limit) {
        result.push_back(currentNumber);
        currentNumber *= base;
    }

    return result;
}

int main() {
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.precision(10);

    int n;
    cin >> n;

    vector<long long> coordinates(n);

    for (size_t i = 0; i < n; ++i) {
        cin >> coordinates[i];
    }

    sort(coordinates.begin(), coordinates.end());

    auto powersOf2 = powers(2, 1e10);

    vector<long long> sequence{coordinates[0]};

    for (const auto &point: coordinates) {
        for (const auto &pwr: powersOf2) {
            long long lessPoint = point - pwr;
            long long biggerPoint = point + pwr;

            bool lessPointPresent = binary_search(coordinates.begin(), coordinates.end(), lessPoint);
            bool biggerPointPresent = binary_search(coordinates.begin(), coordinates.end(), biggerPoint);

            if (lessPointPresent && biggerPointPresent && sequence.size() < 3)
                sequence = {lessPoint, point, biggerPoint};

            if (lessPointPresent && sequence.size() < 2)
                sequence = {lessPoint, point};

            if (biggerPointPresent && sequence.size() < 2)
                sequence = {point, biggerPoint};
        }
    }

    cout << sequence.size() << endl;

    for (auto const &v: sequence)
        cout << v << ' ';
    cout << endl;

    return 0;
}
