#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;


class LexStringGenerator {
private:
    int start;
    int stop;

    class LexString {
    private:
        int value;

    public:
        LexString(int value)
            : value(value) {}

        static string value_to_string(int value) {
            string result = "";

            while (value) {
                if (value % 26 == 0) {
                    result += 'Z';
                    --value;
                } else
                    result += (char)(value % 26 + 64);

                value /= 26;
            }

            reverse(result.begin(), result.end());

            return result;
        }

        static int string_to_value(string s) {
            int result = 0;

            for (size_t i = 0; i < s.size(); ++i) {
                result = result * 26 + (int)s[i] - 64;
            }

            return result;
        }

        bool operator!=(const LexString& other) const {
            return value < other.value;
        }

        LexString& operator++() {
            ++value;
            return *this;
        }

        string operator*() {
            return value_to_string(value);
        }
    };

public:
    LexStringGenerator(string start, int range) {
        this->start = LexString::string_to_value(start);
        this->stop = this->start + range + 1;
    }

    LexString begin() const {
        return LexString(start);
    }

    LexString end() const {
        return LexString(stop);
    }
};


int main() {
    string s;
    int n;

    cin >> s >> n;

    for (const auto& i: LexStringGenerator(s, n))
        cout << i << endl;

    return 0;
}
