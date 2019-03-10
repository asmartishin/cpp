#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <vector>
#include <exception>

using namespace std;

long long gcd(long long n, long long m) {
    while (m) {
        n %= m;
        swap(n, m);
    }

    return n;
}

long long lcm(long long n, long long m) {
    return n * m / gcd(n, m);
}

class Rational {
public:
    Rational()
        : Numerator_(0)
        , Denominator_(1)
    {}

    Rational(long long numerator, long long denominator) {
        if (denominator == 0) {
            throw invalid_argument("");
        }

        bool isNegative = false;
        if (numerator * denominator < 0) {
            isNegative = true;
        }
        numerator = abs(numerator);
        denominator = abs(denominator);
        auto d = gcd(numerator, denominator);

        Numerator_ = numerator / d * (isNegative ? -1 : 1);
        Denominator_ = denominator / d;
    }

    long long Numerator() const {
        return Numerator_;
    }

    long long Denominator() const {
        return Denominator_;
    }
private:
    long long Numerator_;
    long long Denominator_;
};

bool operator==(const Rational& lhs, const Rational& rhs) {
    return lhs.Numerator() == rhs.Numerator() &&
        lhs.Denominator() == rhs.Denominator();
}

Rational operator+(const Rational& lhs, const Rational& rhs) {
    auto l = lcm(lhs.Denominator(), rhs.Denominator());

    return Rational(
        lhs.Numerator() * l / lhs.Denominator() + rhs.Numerator() * l / rhs.Denominator(),
        l
    );
}

Rational operator-(const Rational& lhs, const Rational& rhs) {
    auto l = lcm(lhs.Denominator(), rhs.Denominator());

    return Rational(
        lhs.Numerator() * l / lhs.Denominator() - rhs.Numerator() * l / rhs.Denominator(),
        l
    );
}

Rational operator*(const Rational& lhs, const Rational& rhs) {
    return Rational(
        lhs.Numerator() *  rhs.Numerator(),
        lhs.Denominator() * rhs.Denominator()
    );
}

Rational operator/(const Rational& lhs, const Rational& rhs) {
    if (rhs.Numerator() == 0) {
        throw domain_error("");
    }
    return lhs * Rational(rhs.Denominator(), rhs.Numerator());
}

ostream& operator<<(ostream& stream, const Rational& number) {
    stream << number.Numerator() << '/' << number.Denominator();
    return stream;
}

istream& operator>>(istream& stream, Rational& number) {
    long long numerator, denominator;
    char c;

    stream >> numerator >> c >> denominator;

    if (stream && c == '/') {
        number = {numerator, denominator};
    }

    return stream;
}

bool operator<(const Rational& lhs, const Rational& rhs) {
    return (lhs - rhs).Numerator() < 0;
}

int main() {
    Rational r1, r2;
    char c;

    try {
        cin >> r1 >> c >> r2;
        switch (c) {
            case '+':
                cout << r1 + r2 << endl;
                break;
            case '-':
                cout << r1 - r2 << endl;
                break;
            case '*':
                cout << r1 * r2 << endl;
                break;
            case '/':
                cout << r1 / r2 << endl;
                break;
        }
    } catch (invalid_argument&) {
        cout << "Invalid argument" << endl;
    } catch (domain_error&) {
        cout << "Division by zero" << endl;
    }

    return 0;
}
