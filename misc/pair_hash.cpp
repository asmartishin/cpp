#include <iostream>
#include <unordered_set>
#include <functional>


//namespace std {
//    template<>
//    struct hash<std::pair<int, int> > {
//        size_t operator()(const std::pair<int, int> &p) const {
//            return std::hash<int>()(p.first) ^ std::hash<int>()(p.second);
//        }
//    };
//}


struct PairHash {
    inline size_t operator()(const std::pair<int, int> &p) const {
        return std::hash<int>()(p.first) ^ std::hash<int>()(p.second);
    }
};


int main() {
    std::unordered_set<std::pair<int, int>, PairHash > s;
    std::pair<int, int> p = std::make_pair(1, 2);

    s.insert(p);

    std::cout << (s.find(p) != s.end()) << std::endl;
}
