#include <iostream>
#include <vector>
#include <limits>

using namespace std;


vector<int> unionOfLists(vector<int> &v1, vector<int> &v2) {
    vector<int> result;
    int i1 = 0;
    int i2 = 0;

    while (i1 < v1.size() && i2 < v2.size()) {
        if (v1[i1] <= v2[i2])
            result.push_back(v1[i1++]);
        else
            result.push_back(v2[i2++]);
    }

    for (size_t i = i1; i < v1.size(); ++i)
        result.push_back(v1[i]);

    for (size_t i = i2; i < v2.size(); ++i)
        result.push_back(v2[i]);

    return result;
}


vector<int> intersectionOfLists(vector<int> &v1, vector<int> &v2) {
    vector<int> result;
    int j = 0;
    int last_number = numeric_limits<int>::max();

    for (size_t i = 0; i < v1.size(); ++i) {
        if (j >= v2.size())
            break;

        while (j < v2.size() && v1[i] > v2[j])
            ++j;

        if (last_number != v1[i] && v2[j] == v1[i]) {
            result.push_back(v1[i]);
            ++j;
        }
        last_number = v1[i];
    }

    return result;
}


int main() {
    vector<int> v1{1, 2, 2, 5, 7, 14};
    vector<int> v2{2, 2, 4, 7, 9, 14, 15};

    for (auto const &v: unionOfLists(v1, v2))
        cout << v << ' ';
    cout << endl;

    for (auto const &v: intersectionOfLists(v1, v2))
        cout << v << ' ';
    cout << endl;

    return 0;
}
