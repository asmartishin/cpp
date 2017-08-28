#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;


int sum1(vector<int> &v) {
    return v[0] + v[1] + v[2];
}

int sum2(vector<int> &v) {
    return v[3] + v[4] + v[5];
}

int is_lucky(vector<int> &v) {
    return sum1(v) == sum2(v);
}

int diff(vector<int> &v1, vector<int> &v2) {
    int diff = 0;

    for (size_t i = 0; i < v1.size(); ++i) {
        if (v1[i] != v2[i]) {
            ++diff;
        }
    }

    return diff;
}


int main() {
    string s;
    int result = 6;
    vector<int> v1(6);
    vector<int> v2(6);

    cin >> s;

    for (size_t i = 0; i < s.size(); ++i) {
        v1[i] = s[i] - '0';
    }

    for (int i1 = 0; i1 <= 9; ++i1)  {
        v2[0] = i1;
        for (int i2 = 0; i2 <= 9; ++i2)  {
            v2[1] = i2;
            for (int i3 = 0; i3 <= 9; ++i3)  {
                v2[2] = i3;
                for (int i4 = 0; i4 <= 9; ++i4)  {
                    v2[3] = i4;
                    for (int i5 = 0; i5 <= 9; ++i5)  {
                        v2[4] = i5;
                        for (int i6 = 0; i6 <= 9; ++i6)  {
                            v2[5] = i6;
                            if (is_lucky(v2)) {
                                if (diff(v1, v2) < result) {
                                    result = diff(v1, v2);
                                }
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
