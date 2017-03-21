#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>

using namespace std;


int main() {
    int numbersCount;
    unordered_set<long long int> numbers;
    long long number;
    string result = "YES";

    cin >> numbersCount;

    for (size_t i = 0; i != numbersCount; ++i) {
        cin >> number;
        if (numbers.count(number)) {
            result = "NO";
        }
        numbers.insert(number);
    }

    cout << result << endl;

    return 0;
}

