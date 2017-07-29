#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;


int main() {
    int n;
    cin >> n;

    string String;
    getline(cin, String);

    vector<vector<char> > Strings;

    for (size_t i = 0; i != n; ++i) {
        getline(cin, String);
        Strings.push_back(vector<char> (String.begin(), String.end()));
    }

    int m = Strings[0].size();
    map<string, int> Distances;
    set<string> Words;

    for (size_t j = 0; j != m; ++j) {
        string String(Strings[0].begin(), Strings[0].end());
        rotate(Strings[0].begin(), Strings[0].begin() + 1, Strings[0].end());
        Words.insert(String);
    }

    for (size_t i = 0; i != n; ++i) {
        string String(Strings[i].begin(), Strings[i].end());
        if (Words.find(String) != Words.end()) {
            for (size_t j = 0; j != m; ++j) {
                string String(Strings[i].begin(), Strings[i].end());
                if (Distances.find(String) == Distances.end() ) {
                    Distances[String] = j;
                } else {
                    Distances[String] += j;
                }
                rotate(Strings[i].begin(), Strings[i].begin() + 1, Strings[i].end());
            }
        } else {
            cout << "-1" << endl;
            return 0;
        }
    }

    vector<int> results;

    for(auto it = Distances.cbegin(); it != Distances.cend(); ++it) {
        results.push_back(it->second);
    }

    cout << *min_element(results.begin(), results.end()) << endl;

    return 0;
}
