#include <iostream>
#include <vector>
#include <thread>
#include <mutex>

using namespace std;


class Wallet {
    int money_;
    mutex mutex_;
public:
    Wallet(): money_(0) {}
    int get_money() {
        return money_;
    }

    void add_money(int money) {
        lock_guard<mutex> lockGuard(mutex_);

        for (size_t i = 0; i < money; ++i) {
            ++money_;
        }
    }
};


int test_multithreaded_wallet() {
    Wallet wallet;
    vector<thread> threads;

    for (size_t i = 0; i < 5; ++i)
        threads.push_back(thread(&Wallet::add_money, ref(wallet), 1000));

    for (size_t i = 0; i < threads.size(); ++i)
        threads.at(i).join();

    return wallet.get_money();
}


int main () {
    cout << test_multithreaded_wallet() << endl;

    return 0;
}
