#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void findRow(long long n) {
    vector<char> letters = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    string result = "";

    while (true) {
        if (n > 26) {
            if (n % 26 != 0) {
                result += letters[n - (n / 26) * 26 - 1];
                n /= 26;
            } else {
                result += letters[25];
                n = n / 26 - 1;
            }
        } else {
            result += letters[n - 1];
            break;
        }
    }

    reverse(result.begin(), result.end());

    cout << result << endl;
}

int main() {
    int testsCount;
    long long n;
    cin >> testsCount;
    for (size_t i = 0; i != testsCount; ++i) {
        cin >> n;
        findRow(n);
    }
    return 0;
}
