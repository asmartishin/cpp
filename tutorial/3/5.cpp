#include <iostream>

using namespace std;


int pow(const int a, const int b) {
    if (b == 0) {
        return 1;
    } else {
        return pow(a, b - 1) * a;
    }
}

int main() {
    int a, b;
    cin >> a >> b;

    cout << pow(a, b) << endl;
    return 0;
}
