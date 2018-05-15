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
#include <limits>
#include <cassert>
#include <fstream>
#include <array>

using std::cout;
using std::cin;
using std::string;
using std::vector;

#define endl '\n'


bool isValid(string s) {
    std::unordered_map<char, char> openToClosedBracket{{'(', ')'}, {'{', '}'}, {'[', ']'}};
    std::stack<char> bracketStack;

    for (const auto &bracket: s) {
        if (openToClosedBracket.find(bracket) == openToClosedBracket.end()) {
            if (!bracketStack.empty()) {
                if (bracketStack.top() != bracket) {
                    return false;
                } else {
                    bracketStack.pop();
                }
            } else {
                return false;
            }
        } else {
            bracketStack.push(openToClosedBracket[bracket]);
        }
    }

    if (!bracketStack.empty()) {
        return false;
    }

    return true;
}

int main() {
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.precision(10);

    string s;
    cin >> s;

    cout << isValid(s) << endl;

    return 0;
}
