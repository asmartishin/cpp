#include <iostream>
#include <vector>
#include <set>

using namespace std;


long long solution(vector<int>& d, int n) {
    long long result = n;
    set<int> s;
    for (size_t i = 0; i < n; ++i) {
        s.insert(d[i]);
        if (s.find(d[i] - 1) != s.end()) {
            --result;
        }
    }
    return result;
}


long long nsolution(vector<int>& d, int n) {
    long long result = 0;
    int task = 0;
    while (task != n) {
        ++result;
        for (size_t i = 0; i < n; ++i) {
            if (d[i] == task + 1) {
                ++task;
            }
        }
    }
    return result;
}

int main() {
    int n, m;
    cin >> n;
    vector<int> d;

    for (size_t i = 0; i < n; ++i) {
        cin >> m;
        d.push_back(m);
    }

    cout << solution(d, n) << endl;

//    do {
//        for (size_t i = 0; i < n; ++i) {
//            cout << d[i];
//        }
//        cout << endl;
//        cout << solution(d, n) << ' ' << nsolution(d, n) << endl;
//    } while ( next_permutation(d.begin(), d.end()) );

    return 0;
}
