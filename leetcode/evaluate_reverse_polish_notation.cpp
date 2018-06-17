#include <iostream>
#include <vector>
#include <stack>

using namespace std;


int evalRPN(vector<string> &tokens) {
    stack<int> st;

    for (size_t i = 0; i < tokens.size(); ++i) {
        if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/") {
            int b = st.top();
            st.pop();
            int a = st.top();
            st.pop();

            switch (tokens[i][0]) {
                case('+'):
                    st.push(a + b);
                    break;
                case('-'):
                    st.push(a - b);
                    break;
                case('*'):
                    st.push(a * b);
                    break;
                case('/'):
                    st.push(a / b);
                    break;
            }
        } else {
            st.push(stoi(tokens[i]));
        }
    }

    return st.top();
}


int main() {
    vector<string> tokens{"4", "13", "5", "/", "+"};
    cout << evalRPN(tokens) << endl;

    return 0;
}
