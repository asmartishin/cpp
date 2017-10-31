#include <iostream>
#include <vector>
#include <climits>

using namespace std;


void PairSumCloseToNumber(vector<int> numbers, int sum) {
    int diff = INT_MAX;

    int l = 0;
    int r = numbers.size();

    pair<int, int> result;

    while (l < r) {
        if (abs(numbers[l] + numbers[r] - sum) < diff) {
            diff = abs(numbers[l] + numbers[r] - sum);
            result = make_pair(numbers[l], numbers[r]);
        } else if (numbers[l] + numbers[r] < sum)
            ++l;
        else
            --r;
    }

    cout << result.first << ' ' << result.second << endl;

    return;
}


int main() {
    int n, sum;
    cin >> n >> sum;
    vector<int> numbers(n);

    for (size_t i = 0; i < n; ++i)
        cin >> numbers[i];

    sort(numbers.begin(), numbers.end());
    PairSumCloseToNumber(numbers, sum);

    return 0;
}
