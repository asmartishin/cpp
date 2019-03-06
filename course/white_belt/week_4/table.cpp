#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main() {
    ifstream input("input.txt");
    int n, m;
    int number;

    input >> n >> m;
    size_t i = 0;

    while (input >> number) {
        cout << setw(10) << number;
        input.ignore(1);

        if (++i % m == 0) {
            cout << endl;
        } else {
            cout << ' ';
        }
    }

    return 0;
}
