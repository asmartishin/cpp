#include <iostream>

using namespace std;


double binpow(double n, int p) {
    double result = 1;
    int abs_p = abs(p);

    while (abs_p) {
        if (abs_p % 2 == 1)
            result *= n;
        n *= n;
        abs_p /= 2;
    }

    return p > 0 ? result: 1 / result;
}


int main() {
    double n;
    int p;

    cin >> n >> p;

    cout << binpow(n, p) << endl;

    return 0;
}
