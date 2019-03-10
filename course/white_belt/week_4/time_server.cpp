#include <iostream>
#include <exception>
#include <string>
#include <system_error>
using namespace std;

string AskTimeServer() {
    throw std::system_error(EDOM, std::generic_category());
}

class TimeServer {
public:
    string GetCurrentTime() {
        string t;

        try {
            t = AskTimeServer();
        } catch (system_error&) {
            t = LastFetchedTime;
        }

        LastFetchedTime = t;

        return t;
    }

private:
    string LastFetchedTime = "00:00:00";
};

int main() {
    TimeServer ts;
    try {
        cout << ts.GetCurrentTime() << endl;
    } catch (exception& e) {
        cout << "Exception got: " << e.what() << endl;
    }
    return 0;
}
