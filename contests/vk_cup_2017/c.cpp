#include <iostream>
#include <vector>
#include <sstream>
#include <limits>

using namespace std;


int main() {
    int n;
    int k;
    string input;
    string is_effective;
    vector<bool> effectiveness;
    vector<string> names;
    string name;
    int nameSize = 1;
    vector<int> currentLetter {1,0};

    const vector<char> letters {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};

    cin >> n >> k;

    if (n > 26) {
        nameSize = 2;
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, input);
    std::istringstream buffer(input);
    while (buffer >> is_effective) {
        if (is_effective == "YES") {
            effectiveness.push_back(true);
        } else {
            effectiveness.push_back(false);
        }
    }

    for (size_t i = n - k + 1; i != n; ++i) {
        effectiveness.push_back(true);
    }

    names.push_back("A");

    for (size_t i = 0; i != n; ++i) {
        if (currentLetter[0] > 26) {
            currentLetter[1]++;
            currentLetter[0] = 0;
        }
        if (!effectiveness[i]) {
            names.push_back(names.back());
        } else {
            name = toupper(letters[currentLetter[0]]);
            if (nameSize > 1) {
                name += letters[currentLetter[1]];
            }
            currentLetter[0]++;
            names.push_back(name);
        }
        cout << effectiveness[i] << ' ' << name << endl;
    }

    for (size_t i = 0; i != names.size(); ++i) {
        cout << names[i] << ' ';
    }
    cout << endl;

    return 0;
}
