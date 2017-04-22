#include <iostream>

using namespace std;


int main() {
    long long n;

    cin >> n;

    long long k = 1;

    while (!(n % k)) {
        k++;
    }

    cout << k << endl;

    return 0;
}
