#include <iostream>
#include <memory>

class ParentClass {
public:
    ParentClass(int value)
        : Value(value)
    {
        std::cout << "Call parent constructor" << std::endl;
    }

    virtual ~ParentClass() {
        std::cout << "Call parent destructor" << std::endl;
    }

    int GetValue() const {
        return Value;
    }
private:
    int Value;
};

class DerivedClass final: public ParentClass {
public:
    DerivedClass(int value, int anotherValue)
        : ParentClass(value)
        , AnotherValue(anotherValue)
    {
        std::cout << "Call child constructor" << std::endl;
    }

    int GetAnotherValue() const {
        return AnotherValue;
    }

    ~DerivedClass() override {
        std::cout << "Call child destructor" << std::endl;
    }
private:
    int AnotherValue;
};

int main() {
    std::unique_ptr<ParentClass> pc = std::make_unique<DerivedClass>(1, 2);

    std::cout << pc->GetValue() << std::endl;
}
