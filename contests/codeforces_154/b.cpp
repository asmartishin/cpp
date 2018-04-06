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
#include <fstream>

using namespace std;

#define endl '\n'


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.precision(10);

    ifstream input;
    ofstream output;

    input.open("input.txt");
    output.open("output.txt");

    int n;
    int v;
    int result = numeric_limits<int>::max();

    input >> n;

    vector<double> c(5001, 0);

    for (size_t i = 0; i < n; ++i) {
        input >> v;
        ++c[v];
    }

    for (size_t i = 1; i < 5001; ++i) {
        int cresult = 0;

        for (size_t j = 1; j < i; ++j) {
            cresult += c[j];
        }

        for (size_t j = i * 2 + 1; j < 5001; ++j) {
            cresult += c[j];
        }

        result = min(result, cresult);
    }

    output << result;

    output.close();

    return 0;
}
