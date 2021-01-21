#include <iostream>
#include <unordered_set>
#include <functional>
#include <string>

namespace std {
    template<>
    struct hash<std::pair<int, int> > {
        size_t operator()(const std::pair<int, int> &p) const {
            return std::hash<int>()(p.first) ^ std::hash<int>()(p.second);
        }
    };
}

struct TPairHash {
    template<typename T1, typename T2>
    inline size_t operator()(const std::pair<T1, T2> &p) const {
        return std::hash<T1>()(p.first) ^ std::hash<T2>()(p.second);
    }
};

int main() {
    std::unordered_set<std::pair<int, std::string>, TPairHash > s;
    std::pair<int, std::string> p = std::make_pair(1, "asd");

    s.insert(p);

    std::cout << (s.find(p) != s.end()) << std::endl;
}
