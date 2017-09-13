#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>

using namespace std;


int main() {
    int divisionBasis;
    int AliceNumbersCount;
    int BobNumbersCount;

    int number;

    vector<int> AliceNumbers;
    vector<int> BobNumbers;

    int divisionResult;

    int result = 0;
    int minRemainder;

    cin >> divisionBasis >> AliceNumbersCount >> BobNumbersCount;

    vector<int> possibleRemainders;

    for (size_t i = 0; i != AliceNumbersCount; ++i) {
        cin >> number;
        AliceNumbers.push_back(number);
    }

    for (size_t i = 0; i != BobNumbersCount; ++i) {
        cin >> number;
        BobNumbers.push_back(number);
    }

    for (size_t i = 0; i != divisionBasis; ++i) {
        possibleRemainders.push_back(0);
    }

    for (size_t i = 0; i != AliceNumbers.size(); ++i) {
        for (size_t j = 0; j != BobNumbers.size(); ++j) {
            divisionResult = (AliceNumbers[i] + BobNumbers[j]) % divisionBasis;
            if (divisionResult == 0) {
                possibleRemainders[0] += 1;
            } else {
                possibleRemainders[divisionBasis - divisionResult] += 1;
            }
        }
    }

    minRemainder = *min_element(possibleRemainders.begin(), possibleRemainders.end());

    for (size_t i = 0; i != possibleRemainders.size(); ++i) {
        if (possibleRemainders[i] == minRemainder) {
            result = i;
            break;
        }
    }

    if (result == 0) {
        result = divisionBasis;
    }

    cout << result << endl;

    return 0;
}

