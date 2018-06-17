#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <limits>

using namespace std;


bool int_overflow(long long n) {
    return (n > numeric_limits<int>::max() || n < numeric_limits<int>::min());
}


int reverse_integer(int n) {
    vector<int> nums;
    long long result = 0;

    while (n) {
        nums.push_back(n % 10);
        n /= 10;
    }

    for (size_t i = 0; i < nums.size(); ++i) {
        result *= 10;
        result += nums[i];
        if (int_overflow(result))
            return 0;
    }

    return (int)result;
}


int main() {
    int n = 1563847412;

    cout << reverse_integer(n) << endl;
    return 0;
}
