#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Image {
    double quality;
    double freshness;
    double rating;
};

struct Params {
    double a;
    double b;
    double c;
};


class FunctionPart {
public:
    FunctionPart(char operation, double value)
        : Operation(operation)
        , Value(value)
    {}

    double Apply(double value) const {
        if (Operation == '+') {
            value += Value;
        } else if (Operation == '-') {
            value -= Value;
        } else if (Operation == '*') {
            value *= Value;
        } else {
            value /= Value;
        }

        return value;
    }

    void Invert() {
        if (Operation == '-') {
            Operation = '+';
        } else if (Operation == '+') {
            Operation = '-';
        } else if (Operation == '*') {
            Operation = '/';
        } else {
            Operation = '*';
        }
    }
private:
    char Operation;
    double Value;
};

class Function {
public:
    void AddPart(char operation, double value) {
        Parts.emplace_back(operation, value);
    }

    double Apply(double value) const {
        for (const auto& part: Parts) {
            value = part.Apply(value);
        }

        return value;
    }

    void Invert() {
        for (auto& part: Parts) {
            part.Invert();
        }

        reverse(begin(Parts), end(Parts));
    }
private:
    vector<FunctionPart> Parts;
};

Function MakeWeightFunction(const Params& params,
                            const Image& image) {
  Function function;
  function.AddPart('*', params.a);
  function.AddPart('-', image.freshness * params.b);
  function.AddPart('+', image.rating * params.c);
  return function;
}

double ComputeImageWeight(const Params& params, const Image& image) {
  Function function = MakeWeightFunction(params, image);
  return function.Apply(image.quality);
}

double ComputeQualityByWeight(const Params& params,
                              const Image& image,
                              double weight) {
  Function function = MakeWeightFunction(params, image);
  function.Invert();
  return function.Apply(weight);
}

int main() {
  Image image = {10, 2, 6};
  Params params = {4, 2, 6};
  cout << ComputeImageWeight(params, image) << endl;
  cout << ComputeQualityByWeight(params, image, 52) << endl;
  return 0;
}
