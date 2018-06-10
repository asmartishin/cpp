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

struct Creature {
    size_t Id;
    int Hp;
    int Damage;
    int Diff;

    Creature(size_t i, int hp, int damage)
        : Id(i + 1)
        , Hp(hp)
        , Damage(damage) {
        Diff = hp - damage;
    }

    bool operator<(const Creature &other) const {
        return Diff > other.Diff;
    }

    int getMax(){
	return  Hp > Damage ? Hp : Damage;
    }
};

int main() {
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.precision(10);

    int n, a, b;
    int damage, hp;
    long long result = 0, summ = 0;

    vector<Creature> creatures;

    cin >> n >> a >> b;

    for (size_t i = 0; i < n; ++i) {
        cin >> hp >> damage;
        creatures.emplace_back(i, hp, damage);
    }

    sort(begin(creatures), end(creatures));

    for (size_t i = 0; i < n; ++i) {
        if (i < b) {
            summ += creatures[i].getMax();
        } else {
            summ += creatures[i].Damage;
        }
    }

    if (a == 0 || b == 0) {
        cout << summ << endl;
        return 0;
    }

    long long hpIncrease = 1 << a;
    for (size_t i = 0; i < n; ++i) {
        long long newResult = summ;

        if (i < b) {
            newResult -= creatures[i].getMax();
            newResult += creatures[i].Hp * hpIncrease;
        } else {
            newResult -= creatures[b - 1].getMax();
            newResult += creatures[b - 1].Damage;

            newResult -= creatures[i].Damage;
            newResult += creatures[i].Hp * hpIncrease;
        }

        result = max(result, newResult);
    }

    cout << result << endl;

    return 0;
}
