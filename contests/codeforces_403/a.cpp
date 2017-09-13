#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    int socksNumber = 0;
    int socksMaxNumber = 0;
    int sock;

    cin >> n;

    vector<int> socks(n, 0);

    for (size_t i = 0; i != 2 * n; ++i) {
        cin >> sock;
        --sock;
        if (++socks[sock] == 1) {
            if (++socksNumber > socksMaxNumber) {
                socksMaxNumber = socksNumber;
            }
        } else {
            --socksNumber;
        }
    }

    cout << socksMaxNumber << endl;

    return 0;
}
