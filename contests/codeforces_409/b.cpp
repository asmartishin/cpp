#include <iostream>
#include <vector>
#include <map>

using namespace std;


int main() {
    string xin, yin, zin;
    map<char, int> m = {{'a', 0}, {'b', 1}, {'c', 2}, {'d', 3}, {'e', 4}, {'f', 5}, {'g', 6}, {'h', 7}, {'i', 8}, {'j', 9}, {'k', 10}, {'l', 11}, {'m', 12}, {'n', 13}, {'o', 14}, {'p', 15}, {'q', 16}, {'r', 17}, {'s', 18}, {'t', 19}, {'u', 20}, {'v', 21}, {'w', 22}, {'x', 23}, {'y', 24}, {'z', 25}};
    vector<char> a = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};

    cin >> xin >> yin;
    vector<char> x(xin.begin(), xin.end());
    vector<char> y(yin.begin(), yin.end());
    vector<char> z;
    bool failed = false;

    for (int i = 0; i != y.size(); ++i) {
        if (m[x[i]] >= m[y[i]]) {
            z.push_back(a[m[y[i]]]);
        } else if (m[x[i]] < m[y[i]]) {
            failed = true;
        }
    }

    if (!failed) {
        for (size_t i = 0; i != z.size(); ++i) {
            cout << z[i];
        }
        cout << endl;
    } else {
        cout << "-1" << endl;
    }

    return 0;
}
