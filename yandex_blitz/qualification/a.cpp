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

using namespace std;

#define endl '\n'


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.precision(10);

    int n, pc, vc, ac, ps = 0, vs = 0;

    cin >> n;

    queue<int> a;

    for (size_t i = 0; i < n; ++i) {
        cin >> ac;
        a.push(ac);
    }

    while (!a.empty()) {
        pc = a.front();
        ps += pc;
        a.pop();

        vc = a.front();
        vs += vc;
        a.pop();

        ac = a.front();
        a.pop();


        if (pc < vc) {
            ps += ac;
        } else {
            vs += ac;
        }
    }

    if (ps > vs) {
        cout << "Petya" << endl;
    } else {
        cout << "Vasya" << endl;
    }

    return 0;
}
