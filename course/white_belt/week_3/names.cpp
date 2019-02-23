#include <iostream>
#include <map>
#include <unordered_set>
#include <numeric>
#include <vector>

using namespace std;

class Person {
public:
    Person(const string& firstName, const string& lastName, int birthday)
     : Birthday(birthday)
    {
         FirstNames[Birthday] = firstName;
         LastNames[Birthday] = lastName;
    }

    void ChangeFirstName(int year, const string& first_name) {
        if (year >= Birthday) {
            FirstNames[year] = first_name;
        }
    }

    void ChangeLastName(int year, const string& last_name) {
        if (year >= Birthday) {
            LastNames[year] = last_name;
        }
    }

    string GetFullName(int year) const {
        if (year < Birthday) {
            return "No person";
        }
        string firstName;
        string lastName;

        auto it = FirstNames.upper_bound(year);

        if (it != FirstNames.begin()) {
            --it;
            firstName = it->second;
        }

        it = LastNames.upper_bound(year);

        if (it != LastNames.begin()) {
            --it;
            lastName = it->second;
        }

        if (firstName.empty() && lastName.empty()) {
            return "Incognito";
        } else if (firstName.empty()) {
            return lastName + " with unknown first name";
        } else if (lastName.empty()) {
            return firstName + " with unknown last name";
        }

        return firstName + " " + lastName;
    }

    string GetNamesHistory(const map<int, string>& names, int year) const {
        vector<string> seenNames;
        map<int, string, std::greater<int>> namesHistory;

        string result;

        for (const auto& [currentYear, currentName]: names) {
            if (currentYear > year) {
                break;
            }

            if (!currentName.empty()) {
                if (!seenNames.empty() && seenNames.back() == currentName) {
                    continue;
                }

                namesHistory[currentYear] = currentName;
                seenNames.push_back(currentName);
            }
        }

        if (namesHistory.empty()) {
            return "";
        }

        auto it = namesHistory.begin();

        result += it->second;
        ++it;

        if (it == namesHistory.end()) {
            return result;
        }

        result += " (";

        result += accumulate(it, namesHistory.end(), string(),
            [](string &result, auto &s) { return result.empty() ? s.second : result + ", " + s.second; }
        );

        result += ")";

        return result;
    }

    string GetFullNameWithHistory(int year) const {
        if (year < Birthday) {
            return "No person";
        }
        auto firstNameHistory = GetNamesHistory(FirstNames, year);
        auto lastNameHistory = GetNamesHistory(LastNames, year);

        if (firstNameHistory.empty() && lastNameHistory.empty()) {
            return "Incognito";
        } else if (firstNameHistory.empty()) {
            return lastNameHistory + " with unknown first name";
        } else if (lastNameHistory.empty()) {
            return firstNameHistory + " with unknown last name";
        }

        return firstNameHistory + " " + lastNameHistory;
    }
private:
    int Birthday;
    map<int, string> FirstNames;
    map<int, string> LastNames;
};

int main() {
    Person person("Polina", "Sergeeva", 1960);
    for (int year : {1959, 1960}) {
        cout << person.GetFullNameWithHistory(year) << endl;
    }

    person.ChangeFirstName(1965, "Appolinaria");
    person.ChangeLastName(1967, "Ivanova");
    for (int year : {1965, 1967}) {
        cout << person.GetFullNameWithHistory(year) << endl;
    }

    return 0;
}
