#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <climits>
#include <cassert>
#include <numeric>

using namespace std;

#define endl '\n'


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.precision(10);

    vector<int> numbers{1, 2, 3, 2, 1};
    int result = 0;

    for (size_t i = 0; i < numbers.size(); ++i)
        result ^= numbers[i];

    cout << result;

    return 0;
}
