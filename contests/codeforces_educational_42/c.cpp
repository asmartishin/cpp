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
#include <climits>
#include <cassert>
#include <fstream>
#include <array>

using namespace std;

#define endl '\n'

bool isPerfectSquare(int n){
    double s = floor(sqrt(n));
    return (s * s == n);
}

template<typename T>
void print(T a) {
    for (auto const &v: a)
        cout << v << ' ';
    cout << endl;
}

vector<int> numberToVector(int n) {
    vector<int> result;

    while (n > 0) {
        result.push_back(n % 10);
        n /= 10;
    }

    reverse(result.begin(), result.end());

    return result;
}

int vectorToNumber(vector<int> &a) {
    int result = 0;

    for (auto const &v: a) {
        result *= 10;
        result += v;
    }

    return result;
}

vector<int> numberToBinVector(int n, size_t size) {
    vector<int> result;

    while (n > 0) {
        if (n % 2 == 0)
            result.push_back(0);
        else
            result.push_back(1);
        n /= 2;
    }

    for (size_t i = result.size(); i < size; ++i)
        result.push_back(0);

    reverse(result.begin(), result.end());

    return result;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.precision(10);

    int n;

    cin >> n;

    auto number = numberToVector(n);
    int minDiff = numeric_limits<int>::max();

    for (size_t i = 1; i <= pow(2, number.size()); ++i) {
        auto subset = numberToBinVector(i, number.size());

        vector<int> subsetNumber;

        for (size_t j = 0; j < number.size(); ++j) {
            if (subset[j] == 1)
                subsetNumber.push_back(number[j]);
        }

        if (subsetNumber.front() == 0)
            continue;

        if (isPerfectSquare(vectorToNumber(subsetNumber)))
            minDiff = min(minDiff, (int)(number.size() - subsetNumber.size()));
    }

    if (minDiff == numeric_limits<int>::max())
        cout << -1 << endl;
    else
        cout << minDiff << endl;

    return 0;
}
