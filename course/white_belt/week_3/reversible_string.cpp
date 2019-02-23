#include <iostream>
#include <algorithm>

using namespace std;

class ReversibleString {
public:
    ReversibleString(const string& s)
        : String(s)
    {}

    ReversibleString() {}

    string ToString() const {
        return String;
    }

    void Reverse() {
        reverse(begin(String), end(String));
    }
private:
    string String;
};

int main() {
  ReversibleString s("live");
  s.Reverse();
  cout << s.ToString() << endl;

  s.Reverse();
  const ReversibleString& s_ref = s;
  string tmp = s_ref.ToString();
  cout << tmp << endl;

  ReversibleString empty;
  cout << '"' << empty.ToString() << '"' << endl;

  return 0;
}
