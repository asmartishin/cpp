#include <memory>
#include <initializer_list>
#include <iostream>

using namespace std;

template <typename T>
class Vector {
private:
    size_t size_;
    size_t capacity_;
    unique_ptr<T[]> values_;
public:
    Vector()
        : size_(0), capacity_(0)
    {
        values_ = make_unique<T[]>(0);
    }

    Vector(int size)
        : size_(0), capacity_(size * 2)
    {
        values_ = make_unique<T[]>(capacity_);
    }

    Vector(initializer_list<T> init_list) {
        size_ = 0;
        capacity_ = size_ * 2;

        values_ = make_unique<T[]>(capacity_);

        for (auto const &v: init_list)
            push_back(v);
    }

    Vector(const Vector &other) {
        *this = other;
    }

    Vector(Vector &&other) {
        capacity_ = other.capacity_;
	size_ = other.size();
        values_ = move(other.values_);

        other.clear();
    }

    const Vector & operator=(const Vector &other) {
        capacity_ = other.capacity_;
        size_ = other.size();
        values_ = make_unique<T[]>(capacity_);

        for (size_t i = 0; i < size_; ++i)
            values_[i] = other.values_[i];

        return *this;
    }

    void push_back(const T &value) {
        if (size_ == capacity_)
            resize(2 * capacity_);

        values_[size_++] = value;
    }

    void pop_back() {
        values_[size_ - 1].~T();
        --size_;
    }

    void resize(size_t new_size) {
        capacity_ = new_size * 2;
        size_ = size_ < new_size ? size_ : new_size;

        auto new_values = make_unique<T[]>(capacity_);

        for (size_t i = 0; i < size_; ++i)
            new_values[i] = values_[i];

        values_ = move(new_values);
    }

    T front() {
        return values_[0];
    }

    T back() {
        return values_[size_ - 1];
    }

    bool empty() const {
        return size() == 0;
    }

    size_t size() const {
        return size_;
    }

    void clear() {
        size_ = 0;
        capacity_ = 0;
        values_.reset();
    }

    T& operator[](int index) {
        return values_[index];
    }

    T* begin() {
        return values_.get();
    }

    T* end() {
        return values_.get() + size_;
    }

    void print() {
        for (auto const &v: *this)
            cout << v << ' ';
        cout << endl;
    }
};


int main() {
    Vector<int> v{1, 2, 3};

    Vector<int> v1(move(v));

    for (size_t i = 4; i < 100; ++i)
        v1.push_back(i);

    v1.print();
    v1.pop_back();
    v1.print();
}
