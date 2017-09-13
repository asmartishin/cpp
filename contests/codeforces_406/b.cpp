#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;


int main() {
    int n, m, k;
    cin >> n >> m;

    string result = "NO";

    int person;
    unordered_set<int> group;
    bool found;

    for (size_t i = 0; i < m; ++i) {
        group.clear();
        cin >> k;
        found = false;
        for (size_t j = 0; j < k; ++j) {
            cin >> person;

            if (group.find(person * -1) == group.end()) {
                group.insert(person);
            } else {
                found = true;
                break;
            }
        }
        if (!found) {
            result = "YES";
            break;
        }
    }

    cout << result << endl;

    return 0;
}
