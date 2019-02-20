#include <iostream>
#include <vector>
#include <set>

using namespace std;

class SortedStrings {
public:
    void AddString(const string& s) {
        Strings.insert(s);
    }

    vector<string> GetSortedStrings() {
        vector<string> result;

        for (const auto& s: Strings) {
            result.emplace_back(s);
        }

        return result;
    }
private:
    std::multiset<std::string> Strings;
};

void PrintSortedStrings(SortedStrings& strings) {
    for (const string& s : strings.GetSortedStrings()) {
        cout << s << " ";
    }
    cout << endl;
}

int main() {
    SortedStrings strings;

    strings.AddString("first");
    strings.AddString("third");
    strings.AddString("second");
    PrintSortedStrings(strings);

    strings.AddString("second");
    PrintSortedStrings(strings);

    return 0;
}
