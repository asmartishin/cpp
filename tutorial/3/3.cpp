#include <iostream>

using namespace std;

int factorial(const int n) {
    if (n <= 1) {
        return n;
    } else {
        return factorial(n - 1) * n;
    }
}


int main() {
    int n;
    cin >> n;

    cout << factorial(n) << endl;

    return 0;
}
