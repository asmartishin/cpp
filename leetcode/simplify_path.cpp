#include <iostream>
#include <stack>
#include <sstream>
#include <deque>

using namespace std;


string simplifyPath(string path) {
    string result, tmp;
    deque<string> dq;
    stringstream ss(path);

    while (getline(ss, tmp, '/')) {
        if (tmp == "" || tmp == ".")
            continue;

        if (tmp == ".." && !dq.empty())
            dq.pop_back();
        else if (tmp != "..")
            dq.push_back(tmp);
    }

    while (!dq.empty()) {
        result += "/" + dq.front();
        dq.pop_front();
    }

    return result.empty() ? "/" : result;
}


int main() {
    string path = "/abc/...";

    cout << simplifyPath(path) << endl;

    return 0;
}
