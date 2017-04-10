#include <iostream>
#include <cmath>

using namespace std;


double sqrt(const double n) {
    double result, prevoiusResult = 1;

    while (true) {
        result = (prevoiusResult + n / prevoiusResult) / 2;
        if (abs(prevoiusResult - result) < 1e-6) break;
        prevoiusResult = result;
    }
    return result;
}

int main() {
    int n;
    cin >> n;

    cout << sqrt(n) << endl;
    return 0;
}
