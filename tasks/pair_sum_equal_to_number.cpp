#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


void PairSumEqualToNumberBinarySearch(vector<int> numbers, int sum) {
    sort(numbers.begin(), numbers.end());

    for (size_t i = 0; i < numbers.size(); ++i) {
        int number = numbers[i];
        int second_number = sum - numbers[i];

        int l = i + 1;
        int r = numbers.size();

        while (l < r) {
            int m = (l + r) / 2;

            if (numbers[m] == second_number) {
                cout << number << ' ' << second_number << endl;
                return;
            } else if (numbers[m] < sum - numbers[i])
                l = m + 1;
            else
                r = m;
        }
    }

    cout << -1 << endl;
    return;
}


void PairSumEqualToNumberMap(vector<int> numbers, int sum) {
    unordered_map<int, int> m;

    for (size_t i = 0; i < numbers.size(); ++i) {
        ++m[numbers[i]];
    }

    for (size_t i = 0; i < numbers.size(); ++i) {
        int number = numbers[i];
        int second_number = sum - numbers[i];

        if (m.find(second_number) != m.end()) {
            if (second_number == number && m[second_number] == 1)
                continue;

            cout << number << ' ' << second_number << endl;
            return;
        }
    }

    cout << -1 << endl;
    return;
}


int main() {
    int n, sum;
    pair<int, int> result;

    cin >> n >> sum;

    vector<int> numbers(n);

    for (size_t i = 0; i < n; ++i)
        cin >> numbers[i];

    PairSumEqualToNumberMap(numbers, sum);

    return 0;
}
