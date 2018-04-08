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

vector<int> generateSequence() {
    vector<int> result;
    int len = max(rand() % 100, 3);
    for (size_t i = 0; i < len; ++i) {
        result.push_back(rand() % 100);
    }

    return result;
}

vector<int> troubleSort(vector<int> sequence) {
    bool done;

    if (sequence.size() > 2)
        done = false;
    else
        done = true;

    while (!done) {
        done = true;
        for (size_t i = 0; i < sequence.size() - 2; ++i) {
            if (sequence[i] > sequence[i + 2]) {
                done = false;
                swap(sequence[i], sequence[i + 2]);
            }
        }
    }

    return sequence;
}

vector<int> troubleSortFast(vector<int> &sequence) {
    vector<int> evenSequence;
    vector<int> oddSequence;
    vector<int> resultSequence;

    for (size_t i = 0; i < sequence.size(); ++i) {
        auto &divSequence= ((i % 2 == 0) ? evenSequence: oddSequence);

        divSequence.push_back(sequence[i]);
    }

    sort(begin(evenSequence), end(evenSequence), greater<>());
    sort(begin(oddSequence), end(oddSequence), greater<>());

    for (size_t i = 0; i < sequence.size(); ++i) {
        auto &divSequence= ((i % 2 == 0) ? evenSequence: oddSequence);

        resultSequence.push_back(divSequence.back());
        divSequence.pop_back();
    }

    return resultSequence;
}

void solve(vector<int> &sequence) {
    auto troubledSequence = troubleSortFast(sequence);
    sort(begin(sequence), end(sequence));

    for (size_t i = 0; i < sequence.size(); ++i) {
        if (sequence[i] != troubledSequence[i]) {
            cout << i << endl;
            return;
        }
    }

    cout << "OK" << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.precision(10);

    int t;

    cin >> t;

    for (size_t i = 0; i < t; ++i) {
        int n;
        cin >> n;

        vector<int> v(n);

        for (size_t j = 0; j < n; ++j)
            cin >> v[j];

        cout << "Case #" << i + 1 << ": ";

        solve(v);
    }

    return 0;
}
