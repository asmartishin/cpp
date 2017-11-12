#include <iostream>

using namespace std;


class Stack {
    struct Node {
        int data;
        Node *next;
    };
    Node *top;
public:
    Stack() {
        top = nullptr;
    }

    ~Stack() {
        while (top) {
            Node *ptr = top->next;
            delete top;
            top = ptr;
        }
    }

    void push(int data) {
        Node *ptr = new Node;
        ptr->data = data;
        ptr->next = nullptr;
        if (top != nullptr) {
            ptr->next=top;
        }
        top = ptr;
    }

    int pop() {
        if (top != nullptr) {
            Node *ptr = top;
            int data = ptr->data;
            top = top->next;
            delete ptr;
            return data;
        } else {
            throw runtime_error("Stack is empty");
        }
    }

    void print() {
        Node *ptr = top;
        while (ptr != nullptr) {
            cout << ptr->data << endl;
            ptr = ptr->next;
        }
    }
};


template <class T> class SmartPointer {
protected:
    T *ref;
    size_t ref_count;
public:
    SmartPointer(T *ptr) {
        ref = ptr;
        ref_count = 1;
    }

    SmartPointer(SmartPointer<T> &sptr) {
        ref = sptr.ref;
        ref_count = sptr.ref_count;
        ++ref_count;
    }

    T& operator*() {
        return *ref;
    }

    T* operator->() {
        return ref;
    }

    SmartPointer<T> & operator=(const SmartPointer<T> &other) {
        if (this != &other) {
            ref = other.ref;
            ref_count = other.ref_count;
            ++ref_count;
        }
        return *this;
    }

    ~SmartPointer() {
        --ref_count;
        if (ref_count == 0)
            delete ref;
    }
};


int main() {
    SmartPointer<Stack> s(new Stack());
    SmartPointer<Stack> s1 = s;

    s1->push(1);
    s1->push(2);
    s1->push(3);

    s1->print();
}
