#include <iostream>

using namespace std;


int gcd(int n, int k) {
    while (k) {
        n %= k;
        swap(n, k);
    }
    return n;
}


int main() {
    int n, k;

    cin >> n >> k;

    cout << gcd(n, k) << endl;

    return 0;
}
