#include <iostream>
#include <vector>
#include <map>

using MyMap = std::map<std::string, int>;
typedef std::vector<int> MyVector;

template <typename T, typename U>
std::ostream& operator<<(std::ostream& out, const std::pair<T, U>& p) {
    out << "[" << p.first << ", " << p.second << "]";
    return out;
}

template <template <typename, typename...> class ContainerType,
         typename ValueType, typename... Args>
void printContainer(const ContainerType<ValueType, Args...>& c) {
    for (const auto& v: c) {
        std::cout << v << ' ';
    }
    std::cout << std::endl;
}

int main() {
    MyMap m{{"as", 1}, {"ab", 2}};
    MyVector v{1, 2, 3};

    printContainer(m);
    printContainer(v);

    return 0;
}
