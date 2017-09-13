#include <iostream>
#include <algorithm>

using namespace std;


long long factorial(int n) {
    long long result = 1;
    for (size_t i = 2; i <= n; ++i) {
        result *= i;
    }
    return result;
}


int main() {
    int a, b;
    cin >> a >> b;
    cout << factorial(min(a, b)) << endl;
    return 0;
}
