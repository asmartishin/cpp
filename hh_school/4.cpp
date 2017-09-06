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

using namespace std;

#define endl '\n'

int number1(int r, int u, int q, int t) {
    return 1000 * r + 100 * u + 10 * q + t;
}

int number2(int r, int q) {
    return 100 * r + 10 * q + q;
}

int number3(int r, int v, int q, int t) {
    return 1000 * r + 100 * v + 10 * q + t;
}

bool checkConsistency(vector<int> values) {
    bool result = true;
    int size = values.size();

    for (size_t i = 0; i < size; ++i) {
        for (size_t j = i + 1; j < size; ++j) {
            if (values[i] == values[j]) {
                result = false;
                break;
            }
        }
    }

    return result;
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.precision(10);

    int n1, n2, n3;
    int result = 0;

    for (int r = 1; r <= 9; ++r) {
        for (int u = 0; u <= 9; ++u) {
            for (int q = 0; q <= 9; ++q) {
                for (int t = 0; t <= 9; ++t) {
                    for (int v = 0; v <= 9; ++v) {
                        vector<int> values = {r, u, q, t, v};
                        if (checkConsistency(values)) {
                            n1 = number1(r, u, q, t);
                            n2 = number2(r, q);
                            n3 = number3(r, v, q, t);
                            if (n1 + n2 == n3) {
                                ++result;
                            }
                        }
                    }
                }
            }
        }
    }

    cout << result << endl;

    return 0;
}
