#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class MyClass {
public:
    MyClass() = default;

    MyClass(int i)
        : Data(i)
    {
        std::cout << "call constructor with " << i << " value" << std::endl;
    }

    int GetData() const {
        return Data;
    }

    size_t operator()(const MyClass& mc) const {
        return std::hash<int>()(mc.Data);
    }

    bool operator==(const MyClass& other) const {
        return Data == other.Data;
    }
private:
    int Data;
};

namespace std {
    template<>
    struct hash<MyClass> {
        size_t operator()(const MyClass& mc) const {
            return std::hash<int>()(mc.GetData());
        }
    };
}

int main() {
    unordered_set<MyClass> mc;

    mc.insert(MyClass(3));
    mc.insert(MyClass(3));
    mc.insert(MyClass(1));

    cout << mc.size() << endl;

    return 0;
}
