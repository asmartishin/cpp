#include <iostream>
#include <vector>

using namespace std;


void generateParenthesisHelper(string s, int ob, int cb, int st, int n, vector<string> &result) {
    if (s.size() == n)
        result.push_back(s);

    if (ob > 0)
        generateParenthesisHelper(s + '(', ob - 1, cb, st + 1, n, result);

    if (cb > 0 && st > 0)
        generateParenthesisHelper(s + ')', ob, cb, st - 1, n, result);
}


vector<string> generateParenthesis(int n) {
    vector<string> result;
    string s = "(";
    int ob = n - 1;
    int cb = n;
    int st = 1;

    generateParenthesisHelper(s, ob, cb, st, n * 2, result);

    return result;
}


int main() {
    int n = 3;

    for (auto const& v: generateParenthesis(n))
        cout << v << endl;
    return 0;
}
