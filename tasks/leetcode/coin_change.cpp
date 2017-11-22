#include <iostream>
#include <vector>
#include <limits>

using namespace std;


int coinChange(vector<int> &coins, int amount) {
    int max_amount = amount + 1;
    vector<int> states(amount + 1, max_amount);

    states[0] = 0;

    for (size_t i = 1; i <= amount; ++i) {
        for (size_t j = 0; j < coins.size(); ++j) {
            if (coins[j] <= i)
               states[i] = min(states[i], states[i - coins[j]] + 1);
        }
    }

    return states[amount] > amount ? -1 : states[amount];
}


int main() {
    vector<int> coins{3};
    int amount = 4;

    cout << coinChange(coins, amount) << endl;

    return 0;
}
