#include <iostream>

using namespace std;

int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    long long s1 = b;
    long long s2 = d;

    long long result = -1;

    if (s1 == s2) {
        result = s1;
    } else {
        for (size_t i = 0; i < 1e6; ++i) {
            s1 += a;

            if ((s1 - d) % c == 0) {
                result = s1;
                break;
            }
        }
    }

    cout << result << endl;

    return 0;
}
