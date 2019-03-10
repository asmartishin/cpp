#include <iostream>
#include <sstream>

using namespace std;

void EnsureEqual(const string& lhs, const string& rhs) {
    if (lhs != rhs) {
        stringstream ss;
        ss << lhs << " != " << rhs;
        throw runtime_error(ss.str());
    }
}

int main() {
    try {
        EnsureEqual("C++ White", "C++ Yellow");
    } catch (const runtime_error& e) {
        cout << e.what() << endl;
    }

    return 0;
}
