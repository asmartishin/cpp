#include <iostream>
#include <vector>

using namespace std;


int main() {
    string String;
    getline (cin, String);

    vector<char> Characters(String.begin(), String.end());

    int start = 0;
    int end = Characters.size() - 1;
    bool swapped = false;
    bool failed = true;

    while (start < end) {
        if (Characters[start++] != Characters[end--]) {
            if (!swapped) {
                swapped = true;
                failed = false;
            } else {
                failed = true;
                break;
            }
        }
    }

    if (failed && !swapped && Characters.size() % 2) {
        failed = false;
    }

    if (failed) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
    }

    return 0;
}
