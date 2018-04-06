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

    int n, m;
    char maxChar;
    char minChar;

    input.open("input.txt");
    output.open ("output.txt");

    input >> n >> m;

    int maxNumber = max(n, m);
    int minNumber = min(n, m);

    if (n > m) {
        maxChar = 'B';
        minChar = 'G';
    } else {
        maxChar = 'G';
        minChar = 'B';
    }

    for (size_t i = 0; i < maxNumber; ++i) {
        output <<  maxChar;

        if (minNumber > 0) {
            output << minChar;
            --minNumber;
        }
    }

    output.close();

    return 0;
}
