#include <iostream>
#include <vector>

using namespace std;


int main() {
    int n;

    cin >> n;

    vector<int> result = {1, 1};

    for (size_t i = 2; i < n + 1; ++i) {
        result.push_back(0);
        for (size_t j = 1; j < i + 1; ++j) {
            result.back() += result[j - 1] * result[i - j];
        }
    }

    cout << result[n] << endl;
}
