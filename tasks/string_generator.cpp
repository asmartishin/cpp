#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;


class LexStringGenerator {
private:
    int range;

    class LexString{
    private:
        int range;
        int value;

        unordered_map<int, char> int_to_char{{
            {1, 'A'}, {2, 'B'}, {3, 'C'}, {4, 'D'}, {5, 'E'}, {6, 'F'}, {7, 'G'}, {8, 'H'}, {9, 'I'}, {10, 'J'},
            {11, 'K'}, {12, 'L'}, {13, 'M'}, {14, 'N'}, {15, 'O'}, {16, 'P'}, {17, 'Q'}, {18, 'R'},
            {19, 'S'}, {20, 'T'}, {21, 'U'}, {22, 'V'}, {23, 'W'}, {24, 'X'}, {25, 'Y'}, {0, 'Z'}
        }};

        string value_to_string(const int value) {
            int tmp_value = value;
            string result = "";

            while (tmp_value) {
                result += int_to_char[tmp_value % 26];

                if (tmp_value % 26 == 0)
                    --tmp_value;

                tmp_value /= 26;
            }

            reverse(result.begin(), result.end());

            return result;
        }

    public:
        LexString(int range, int value)
            : range(range), value(value) {}

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
    LexStringGenerator(int range)
        : range(range + 1) {}

    LexString begin() const {
        return LexString(range, 1);
    }

    LexString end() const {
        return LexString(range, range);
    }
};


int main() {
    int n;
    cin >> n;

    for (const auto& i: LexStringGenerator(n))
        cout << i << endl;

    return 0;
}
