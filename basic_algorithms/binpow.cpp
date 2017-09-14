#include <iostream>

using namespace std;


int binpow(int n, int k) {
    int result = 1;

    while (k) {
        if (k % 2 == 1)
            result *= n;
        n *= n;
        k /= 2;
    }

    return result;
}


int main() {
    int n, k;

    cin >> n >> k;

    cout << binpow(n, k) << endl;

    return 0;
}
