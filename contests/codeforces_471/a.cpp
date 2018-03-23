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

    double hh, mm, hunger, hunger_increse, bun_price, bun_hunger_decrease, cost;

    cin >> hh >> mm;
    cin >> hunger >> hunger_increse >> bun_price >> bun_hunger_decrease;

    double current_time = 60 * hh + mm;
    double discount_time = 60 * 20;

    if (discount_time > current_time) {
        cost = min(
            0.8 * bun_price * ceil((hunger + (discount_time - current_time) * hunger_increse) / bun_hunger_decrease),
            bun_price * ceil(hunger / bun_hunger_decrease)
        );
    } else {
        cost = 0.8 * bun_price * ceil(hunger / bun_hunger_decrease);
    }

    cout << cost << endl;

    return 0;
}
