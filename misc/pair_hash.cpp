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
    template<typename T1, typename T2>
    inline size_t operator()(const std::pair<T1, T2> &p) const {
        return std::hash<T1>()(p.first) ^ std::hash<T2>()(p.second);
    }
};


int main() {
    std::unordered_set<std::pair<int, double>, PairHash > s;
    std::pair<int, int> p = std::make_pair(1, 2.2);

    s.insert(p);

    std::cout << (s.find(p) != s.end()) << std::endl;
}
