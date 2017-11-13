#include <algorithm>
#include <vector>
#include <string>
#include <utility>
#include <iostream>

using namespace std;


vector<int> numbers_count(int n) {
    vector<int> result;

    while (n) {
        result.push_back(n % 10);
        n /= 10;
    }
    reverse(result.begin(), result.end());
    return result;
}


void rle(string &in_string) {
    pair<char, int> count = make_pair(in_string[0], 1);
    int offset = 0;

    for (size_t i = 1; i < in_string.size(); ++i) {
        if (in_string[i] != count.first) {
            in_string[offset++] = count.first;
            if (count.second > 1) {
                vector<int> numbers = numbers_count(count.second);
                for (auto const &v: numbers)
                    in_string[offset++] = v + '0';
            }

            count.first = in_string[i];
            count.second = 1;
        } else {
            ++count.second;
        }
    }

    in_string[offset++] = count.first;
    if (count.second > 1) {
        vector<int> numbers = numbers_count(count.second);
        for (auto const &v: numbers)
            in_string[offset++] = v + '0';
    }

    in_string.resize(offset);
}


int main() {
    std::string input_string;
    std::cin >> input_string;
    rle(input_string);
    std::cout << input_string;
    return 0;
}
