#include <iostream>
#include <cstdarg>

using namespace std;


template <typename T>
T average(int count, ...) {
    T sum{};

    va_list args;
    va_start(args, count);

    for (size_t i = 0; i < count; ++i) {
        sum += va_arg(args, T);
    }
    va_end(args);

    return sum / count;
}


int main() {
    cout << average<double>(3, 2.0, 2.0, 3.0) << endl;

    return 0;
}
