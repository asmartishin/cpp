#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <memory>

using namespace std;

class MyObj {
public:
    MyObj(int data)
        : Data_(data)
    {}

    virtual int ProcessData() = 0;
    int Data() {
        return Data_;
    }

    virtual ~MyObj() = default;
private:
    int Data_;
};

class MyObjRegular final : public MyObj {
public:
    MyObjRegular(int data)
        : MyObj(data)
    {}

    int ProcessData() final {
        return Data();
    }
};

class MyObjMul final : public MyObj {
public:
    MyObjMul(int data, int mul)
        : MyObj(data)
        , Mul(mul)
    {}

    int ProcessData() final {
        return Data() * Mul;
    }
private:
    int Mul;
};

template <typename T>
class MyContainer {
public:
    MyContainer() = default;

    MyContainer(vector<T> v)
        : V(v)
    {}

    MyContainer(const MyContainer& other) :
        V(other.V)
    {
        cout << "copy constructor" << endl;
    }

    MyContainer& operator=(const MyContainer& other) {
        V = other.V;
        cout << "copy assignment operator" << endl;
        return *this;
    }

    MyContainer(MyContainer&& other)
        : V(move(other.V))
    {
        cout << "move constructor" << endl;
    }

    MyContainer& operator=(MyContainer&& other) {
        V = move(other.V);
        cout << "move assignment operator" << endl;
        return *this;
    }

    typename vector<T>::iterator begin() {
        return V.begin();
    }

    typename vector<T>::iterator end() {
        return V.end();
    }
private:
    vector<T> V;
};

template <typename T>
class MyClass {
public:
    MyClass() {}

    void setObj(unique_ptr<MyObj>&& objPtr) {
        ObjPtr = move(objPtr);
    }

    void setContainer(MyContainer<T>&& container) {
        Container = move(container);
    }

    void printData() {
        cout << ObjPtr->ProcessData() << endl;
    }

    void printContainerData() {
        for (const auto & el: Container) {
            cout << el << ' ';
        }
        cout << endl;
    }
private:
    MyContainer<T> Container;
    unique_ptr<MyObj> ObjPtr;
};

int main() {
    MyContainer<int> mc({1,2,3});

    MyClass<int> a;
    a.setObj(make_unique<MyObjRegular>(4));
    a.setContainer(vector<int>{1,2,3});
    a.printData();

    return 0;
}
