#include <iostream>
#include <map>

using namespace std;


int main() {
    int n, k, max_k = 0;
    char c;
    map<char, int> m = {{'a', 0}, {'b', 0}, {'c', 0}, {'d', 0}, {'e', 0}, {'f', 0}, {'g', 0}, {'h', 0}, {'i', 0}, {'j', 0}, {'k', 0}, {'l', 0}, {'m', 0}, {'n', 0}, {'o', 0}, {'p', 0}, {'q', 0}, {'r', 0}, {'s', 0}, {'t', 0}, {'u', 0}, {'v', 0}, {'w', 0}, {'x', 0}, {'y', 0}, {'z', 0}};

    cin >> n >> k;

    for (size_t i = 0; i < n; ++i) {
        cin >> c;
        ++m[c];
    }

    for (auto const& i: m) {
        if (i.second > max_k) {
            max_k = i.second;
        }
    }

    if (max_k <= k) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
