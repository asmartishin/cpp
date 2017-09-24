#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
using boost::multiprecision::cpp_int;

#define endl '\n'


cpp_int reverseNumber(cpp_int number) {
    cpp_int reverse_number = 0;
    do {
        reverse_number = (reverse_number * 10) + (number % 10);
        number /= 10;
    } while (number != 0);
    return reverse_number;
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.precision(10);

    cpp_int number = 0;
    int result = 0;

    for (size_t i = 1; i < 12481; ++i) {
        number = i;
        if (number == reverseNumber(number)) {
            continue;
        }
        for (size_t j = 0; j < 50; ++j) {
            number += reverseNumber(number);
            if (number == reverseNumber(number)) {
                ++result;
                break;
            }
        }
    }

    cout << result << endl;

    return 0;
}
