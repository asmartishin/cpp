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
#include <limits>
#include <cassert>
#include <fstream>
#include <array>

using namespace std;

#define endl '\n'


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.precision(10);

    int n, messageCost, messageDecay, unreadCost, totalTime, result = 0;

    cin >> n >> messageCost >> messageDecay >> unreadCost >> totalTime;

    vector<int> messages(n);

    for (size_t i = 0; i < n; ++i)
        cin >> messages[i];

    sort(begin(messages), end(messages));

    auto cnt = upper_bound(messages.begin(), messages.end(), totalTime) - messages.begin();

    if (unreadCost < messageDecay) {
        result = cnt * messageCost;
    } else {
        for (size_t i = 0; i < cnt; ++i)
            result += messageCost + (unreadCost - messageDecay) * (totalTime - messages[i]);
    }

    cout << result << endl;

    return 0;
}
