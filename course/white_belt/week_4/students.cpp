#include <iostream>
#include <vector>

using namespace std;

struct Student {
    string Name;
    string LastName;
    int Day;
    int Month;
    int Year;
};

int main() {
    size_t n;
    cin >> n;

    string name, lastName;
    int day, month, year;
    vector<Student> students;

    for (size_t i = 0; i < n; ++i) {
        cin >> name >> lastName >> day >> month >> year;
        students.push_back({name, lastName, day, month, year});
    }

    size_t m, idx;
    cin >> m;

    string request;

    for (size_t i = 0; i < m; ++i) {
        cin >> request >> idx;

        if (idx == 0 || idx > n) {
            cout << "bad request" << endl;
            continue;
        }

        --idx;

        auto& student = students[idx];

        if (request == "name") {
            cout << student.Name << ' ' << student.LastName << endl;
        } else if (request == "date") {
            cout << student.Day << '.' << student.Month << '.' << student.Year << endl;
        } else {
            cout << "bad request" << endl;
        }
    }

    return 0;
}
