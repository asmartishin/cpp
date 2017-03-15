#include <iostream>
#include <map>
#include <vector>
#include <set>

using namespace std;


int main() {
    int figuresCount;
    long long result = 0;
    string figure;
    cin >> figuresCount;
    for (size_t i = 0; i < figuresCount; ++i) {
        cin >> figure;
        if (figure.compare("Tetrahedron") == 0) {
            result += 4;
        } else if (figure.compare("Cube") == 0) {
            result += 6;
        } else if (figure.compare("Octahedron") == 0) {
            result += 8;
        } else if (figure.compare("Dodecahedron") == 0) {
            result += 12;
        } else if (figure.compare("Icosahedron") == 0) {
            result += 20;
        }
    }
    cout << result << endl;
    return 0;
}
