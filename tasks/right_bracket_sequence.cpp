#include <iostream>
#include <stack>
#include <unordered_map>
#include <unordered_set>

using namespace std;

unordered_set<char> open_brackets{'(', '[', '{'};
unordered_set<char> close_bracket{')', ']', '}'};

unordered_map<char, char> close_to_open_bracket{{')', '('}, {']', '['}, {'}', '{'}};


bool right_bracket_sequence(string s) {
    stack<char> st;

    for (size_t i = 0; i < s.size(); ++i) {
        if (open_brackets.find(s[i]) != open_brackets.end())
            st.push(s[i]);
        else {
            if (st.size() > 0 && close_to_open_bracket[s[i]] == st.top())
                st.pop();
            else
                return false;
        }
    }

    return true;
}


int main() {
    string s = "(()){}[]";
    string result = "NO";

    if (right_bracket_sequence(s))
        result = "YES";

    cout << result << endl;

    return 0;
}
