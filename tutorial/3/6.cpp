#include <iostream>
#include <cmath>

using namespace std;


double cubeRoot(const double n) {
    double result, prevoiusResult = 1;

    while (true) {
        result = (2 * prevoiusResult + n / (prevoiusResult * prevoiusResult)) / 3;
        if (abs(prevoiusResult - result) < 1e-6) break;
        prevoiusResult = result;
    }
    return result;
}

int main() {
    int n;
    cin >> n;

    cout << cubeRoot(n) << endl;
    return 0;
}
