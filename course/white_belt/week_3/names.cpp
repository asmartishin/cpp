#include <iostream>
#include <map>
#include <unordered_set>
#include <numeric>
#include <vector>

using namespace std;

class Person {
public:
    void ChangeFirstName(int year, const string& first_name) {
        FirstNames[year] = first_name;
    }

    void ChangeLastName(int year, const string& last_name) {
        LastNames[year] = last_name;
    }

    string GetFullName(int year) {
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

    string GetNamesHistory(const map<int, string>& names, int year) {
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

    string GetFullNameWithHistory(int year) {
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
    map<int, string> FirstNames;
    map<int, string> LastNames;
};

int main() {
  Person person;

  person.ChangeFirstName(1965, "Polina");
  person.ChangeLastName(1967, "Sergeeva");
  for (int year : {1900, 1965, 1990}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }

  person.ChangeFirstName(1970, "Appolinaria");
  for (int year : {1969, 1970}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }

  person.ChangeLastName(1968, "Volkova");
  for (int year : {1969, 1970}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }

  person.ChangeFirstName(1990, "Polina");
  person.ChangeLastName(1990, "Volkova-Sergeeva");
  cout << person.GetFullNameWithHistory(1990) << endl;

  person.ChangeFirstName(1966, "Pauline");
  cout << person.GetFullNameWithHistory(1966) << endl;

  person.ChangeLastName(1960, "Sergeeva");
  for (int year : {1960, 1967}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }

  person.ChangeLastName(1961, "Ivanova");
  cout << person.GetFullNameWithHistory(1967) << endl;

    return 0;
}
