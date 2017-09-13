#include <iostream>

using namespace std;


int main() {
    int n, a, b, p, result = 0, aa = 0;

    cin >> n >> a >> b;

    for (size_t i = 0; i < n; ++i) {
        cin >> p;
        if (p == 1) {
            if (a > 0) {
                --a;
            } else if (b > 0) {
                --b;
                ++aa;
            } else if (aa > 0) {
                --aa;
            } else {
                ++result;
            }
        } else {
            if (b > 0) {
                --b;
            } else {
                result += 2;
            }
        }
    }

    cout << result << endl;

    return 0;
}
