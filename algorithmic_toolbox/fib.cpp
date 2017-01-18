#include <iostream>
#include <vector>

using std::vector;
using std::cin;
using std::cout;


long long fastFib(const int n) {
    vector<long long> numbers(n);
    numbers[0] = 0;
    numbers[1] = 1;
    for (int i = 2; i < n + 1; ++i) {
        numbers[i] = numbers[i - 1] + numbers[i - 2];
    }
    return numbers[n];
}


long long slowFib(int n) {
    if (n <= 1) {
        return n;
    }
    return slowFib(n - 1) + slowFib(n - 2);
}


int main() {
    int n;
    cin >> n;
    cout << fastFib(n) << "\n";
    cout << slowFib(n) << "\n";
}
