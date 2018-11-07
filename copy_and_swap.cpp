#include <iostream>
#include <algorithm>

class SimpleArray {
public:
    SimpleArray(std::size_t size)
        : Size(size)
        , Array(Size ? new int[Size] : nullptr)
    {
        std::cout << "constructor" << std::endl;
    }

    SimpleArray(const SimpleArray& other)
        : Size(other.Size)
        , Array(Size ? new int[Size]: nullptr)
    {
        std::cout << "copy constructor" << std::endl;
        std::copy(other.Array, other.Array + Size, Array);
    }

    friend void swap(SimpleArray& lhs, SimpleArray& rhs) {
        using std::swap;

        swap(lhs.Size, rhs.Size);
        swap(lhs.Array, rhs.Array);
    }

    SimpleArray& operator=(SimpleArray other) {
        swap(*this, other);

        std::cout << "assignment operator" << std::endl;

        return *this;
    }

    ~SimpleArray() {
        delete[] Array;
    }
private:
    std::size_t Size;
    int* Array;
};

int main() {
    SimpleArray firstArray(10);
    SimpleArray secondArray(firstArray);
    secondArray = firstArray;

    return 0;
}
