#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <climits>
#include <cassert>

using namespace std;

#define endl '\n'


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.precision(10);

    int a, b, f, k, result = 0;
    bool success = true;

    cin >> a >> b >> f >> k;

    int bd = b;

    for (size_t i = 0; i < k; ++i) {
        if (i % 2 == 0) {
            if (i != k - 1) {
                if (b < 2 * a - f) {
                    if (b < f) {
                        success = false;
                        break;
                    } else {
                        b = bd;
                        b -= a - f;
                        ++result;
                    }
                } else {
                    b -= a;
                }
            } else {
                if (b < a) {
                    if (b < f) {
                        success = false;
                        break;
                    } else {
                        b = bd;
                        b -= a - f;
                        ++result;
                    }
                }
            }
        } else {
            if (i != k - 1) {
                if (b < a + f) {
                    if (b < a - f) {
                        success = false;
                        break;
                    } else {
                        b = bd;
                        b -= f;
                        ++result;
                    }
                } else {
                    b -= a;
                }
            } else {
                if (b < a) {
                    if (b < a - f) {
                        success = false;
                        break;
                    } else {
                        b = bd;
                        b -= f;
                        ++result;
                    }
                }
            }
        }
    }

    if (success && b >= 0)
        cout << result << endl;
    else
        cout << -1 << endl;

    return 0;
}
