#include <iostream>
#include <vector>

using namespace std;


vector<int> find_primes(int n) {
    vector<bool> numbers(n, true);
    vector<int> result;

    numbers[0] = false;
    numbers[1] = false;

    for (size_t i = 0; i * i < n; ++i) {
        if (numbers[i] == true) {
            for (size_t j = i * i; j < n; j += i) {
                numbers[j] = false;
            }
        }
    }

    for (size_t i = 0; i < n; ++i) {
        if (numbers[i] == true)
            result.push_back(i);
    }

    return result;
}


vector<int> get_divisors(int number) {
    auto primes = find_primes(number);
    vector<int> result;
    size_t pi = 0;

    while (number > 1) {
        if (number % primes[pi] == 0) {
            number /= primes[pi];
            result.push_back(primes[pi]);
        } else
            ++pi;
    }

    return result;
}


int main() {
    int number = 2015;
    auto divisors = get_divisors(number);

    for (auto const &v: divisors)
        cout << v << ' ';

    cout << endl;

    return 0;
}
