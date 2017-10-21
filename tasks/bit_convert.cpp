#include <iostream>
#include <string>
#include <bitset>

using namespace std;


string int_to_bit(int n) {
    return bitset<8>(n).to_string();
}


long bit_to_int(string s) {
    return (int)bitset<8>(s).to_ulong();
}


template<typename T>
string to_bit(T n) {
    string r = "";

    while(n) {
        if (n & 1)
            r += "1";
        else
            r += "0";
        n >>= 1;
    }

    int d = sizeof(T) * 8 - r.size();

    if (d > 0) {
        for (size_t i = 0; i < d; ++i) {
            r += "0";
        }
    }

    reverse(r.begin(), r.end());
    return r;
}


template<typename T>
T from_bit(string s) {
    T r = 0;

    for (size_t i = 0; i < s.size(); ++i) {
        r <<= 1;
        r |= s[i] - '0';
    }

    return r;
}


int main() {
    cout << from_bit<long long>(to_bit<unsigned char>(69) + to_bit<unsigned char>(171) + to_bit<unsigned char>(230) + to_bit<unsigned char>(68)) << endl;
}
