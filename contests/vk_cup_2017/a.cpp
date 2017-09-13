#include <iostream>

using namespace std;

int main() {
    int a;
    int b;
    int years = 0;
    cin >> a;
    cin >> b;

    while (true) {
        a *= 3;
        b *= 2;
        years++;
        if (a > b) {
            break;
        }
    }
    cout << years << endl;
    return 0;
}
