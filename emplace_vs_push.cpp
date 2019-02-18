#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <functional>

std::random_device rd;
std::mt19937 eng(rd());
std::uniform_int_distribution<> distr(97, 122);

constexpr size_t NUMBER_OF_RUNS = 1e5;
constexpr size_t STRING_LENGTH = 30;

struct StringWrapper {
    std::string String;
    size_t Length;
    StringWrapper(const std::string& s)
        : String(s)
        , Length(s.size())
    {
//        std::cout << "INIT" << std::endl;
    }

    StringWrapper(const StringWrapper& other)
        : String(other.String)
        , Length(other.Length)
    {
//         std::cout << "COPY" << std::endl;
    }

    StringWrapper(StringWrapper&& other)
        : String(std::move(other.String))
        , Length(other.Length)
    {
//         std::cout << "MOVE" << std::endl;
    }
};

inline std::string generateString(size_t size) {
    std::string s;

    for (size_t j = 0; j < size; ++j) {
        s += (char)distr(eng);
    }

    return s;
}

void pushToVector() {
    std::vector<StringWrapper> v;
    v.reserve(NUMBER_OF_RUNS);

    for (size_t i = 0; i < NUMBER_OF_RUNS; ++i) {
        v.push_back(StringWrapper(generateString(STRING_LENGTH)));
    }
}

void emplaceToVector() {
    std::vector<StringWrapper> v;
    v.reserve(NUMBER_OF_RUNS);

    for (size_t i = 0; i < NUMBER_OF_RUNS; ++i) {
        v.emplace_back(generateString(STRING_LENGTH));
    }
}

void timeIt(std::function<void ()> func) {
    auto start = std::chrono::high_resolution_clock::now();
    func();
    auto end = std::chrono::high_resolution_clock::now();

    auto dur = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
    std::cout << dur << std::endl;
}

int main() {
    timeIt(pushToVector);
    timeIt(emplaceToVector);

    return 0;
}
