#include <iostream>
#include <memory>

class ParentClass {
public:
    ParentClass(int value)
        : Value(value)
    {
        std::cout << "ParentClass constructor" << std::endl;
    }

    virtual int GetValue() const {
        std::cout << "ParentClass GetValue method" << std::endl;
        return Value;
    }

    virtual ~ParentClass() {
        std::cout << "ParentClass destructor" << std::endl;
    }
protected:
    int Value;
};

class DerivedClass final: public ParentClass {
public:
    DerivedClass(int value, int anotherValue)
        : ParentClass(value)
        , AnotherValue(anotherValue)
    {
        std::cout << "DerivedClass constructor" << std::endl;
    }

    int GetValue() const override {
        std::cout << "DerivedClass GetValue method" << std::endl;
        return Value * 2;
    }

    int GetAnotherValue() const {
        std::cout << "DerivedClass GetAnotherValue method" << std::endl;
        return AnotherValue;
    }

    ~DerivedClass() override {
        std::cout << "DerivedClass destructor" << std::endl;
    }
private:
    int AnotherValue;
};

int main() {
    std::unique_ptr<ParentClass> pc = std::make_unique<DerivedClass>(1, 2);

    std::cout << pc->GetValue() << std::endl;

    // bad design
    auto dc = dynamic_cast<DerivedClass*>(pc.get());

    if (dc) {
        std::cout << dc->GetAnotherValue() << std::endl;
    }

    return 0;
}
