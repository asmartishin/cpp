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


struct TStringCompare {
    bool operator () (const string & s1, const std::string & s2) {
        const size_t s1l = s1.length();
        const size_t s2l = s2.length();

        if(s1l == s2l) {
            return (s1 < s2) ;
        }

        return (s1l < s2l);
    }
};


bool endsWith (string const &s, string const &p) {
    if (s.length() > p.length())
        return (0 == s.compare(s.length() - p.length(), p.length(), p));
    return false;
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.precision(10);

    int n, k;
    unordered_map<string, set<string, TStringCompare> > numbers;
    string person, number;

    cin >> n;

    for (size_t i = 0; i < n; ++i) {
        cin >> person >> k;
        for (size_t j = 0; j < k; ++j) {
            cin >> number;
            numbers[person].insert(number);
        }
    }

    cout << numbers.size() << endl;

    for (auto const &p: numbers) {
        unordered_set<string> person_numbers;
        for (auto const &n1: p.second) {
            bool add = true;
            for (auto const &n2: p.second) {
                if (endsWith(n2, n1))
                    add = false;
            }
            if (add)
                person_numbers.insert(n1);
        }

        cout << p.first << ' ' << person_numbers.size() << ' ';
        for (auto const &n: person_numbers)
            cout << n << ' ';
        cout << endl;
    }

    return 0;
}
