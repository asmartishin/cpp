#include <iostream>
#include <vector>
#include <cmath>

template <typename T>
class Polynom{
    std::vector<T> coefficients;
public:
    Polynom()
    : coefficients()
    {
        coefficients.push_back(0);
        coefficients.push_back(1);
    }
    Polynom(const T& number)
    : coefficients()
    {
        coefficients.push_back(number);
    }

    Polynom& DeleteLeadingZeros(){
        for (size_t i = coefficients.size() - 1; i > 0; --i){
            if (coefficients[i] == 0){
                coefficients.pop_back();
            } else {
                break;
            }
        }
        return *this;
    }

    Polynom& operator+=(const Polynom& other){
        for (size_t i = coefficients.size(); i < other.coefficients.size(); ++i){
            coefficients.push_back(0);
        }

        for (size_t i = 0; i < other.coefficients.size(); ++i){
            coefficients[i] += other.coefficients[i];
        }

        DeleteLeadingZeros();

        return *this;
    }

    Polynom& operator-=(const Polynom& other){
        for (size_t i = coefficients.size(); i < other.coefficients.size(); ++i){
            coefficients.push_back(0);
        }
        for (size_t i = 0; i < other.coefficients.size(); ++i){
            coefficients[i] -= other.coefficients[i];
        }
        DeleteLeadingZeros();
        return *this;
    }

    Polynom operator+(const Polynom& other) const{
        Polynom tmp(*this);
        tmp += other;
        return tmp;
    }

    Polynom operator-(const Polynom& other) const{
        Polynom tmp(*this);
        tmp -= other;
        return tmp;
    }

    Polynom operator*=(const Polynom& other){
        std::vector<T> result_coefficients;
        for (size_t i = 0; i < (coefficients.size() + other.coefficients.size()); ++i){
            result_coefficients.push_back(0);
        }

        for (size_t i = 0; i < coefficients.size(); ++i){
            for (size_t j = 0; j < other.coefficients.size(); ++j){
                result_coefficients[i + j] += coefficients[i] * other.coefficients[j];
            }
        }
        coefficients = result_coefficients;

        DeleteLeadingZeros();
        return *this;
    }

    Polynom operator*(const Polynom& other) const {
        Polynom tmp(*this);
        tmp *= other;
        return tmp;
    }

    friend std::ostream& operator<<(std::ostream& out, const Polynom& other){
        for (size_t i = 0; i < other.coefficients.size(); ++i){
            out << other.coefficients[i] << "*" << "x" << "^" << i;
            if (i + 1 < other.coefficients.size()){
                out << "+";
            }
        }
        return out;
    }

    friend Polynom operator+ (const T& number, const Polynom& other) {
        return other + number;
    }

    friend Polynom operator- (const T& number, const Polynom& other) {
        return other - number;
    }

    friend Polynom operator* (const T& number, const Polynom& other) {
        return other * number;
    }

};

int main(){
    Polynom<int> x;
    std::cout <<  5 * x * x * x + 3 * x + 1;
}
