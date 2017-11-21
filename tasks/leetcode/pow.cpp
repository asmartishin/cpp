#include <iostream>

using namespace std;


double myPow(double x, long long n) {
    double result = 1;

    long long abs_n = abs(n);

    while (abs_n) {
        if (abs_n % 2 == 1)
            result *= x;
        x *= x;
        abs_n /= 2;
    }

    return n > 0 ? result : 1 / result;
}


int main() {
    cout << myPow(2.00000, -2147483648) << endl;

    return 0;
}
