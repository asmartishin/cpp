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
    struct ReferenceCounter {
        size_t count;

        ReferenceCounter()
            : count(0) {}

        size_t AddReference() {
            return ++count;
        }

        size_t RemoveReference() {
            return --count;
        }
    };
    T *ref;
    ReferenceCounter* ref_counter;
public:
    SmartPointer(T *ptr) {
        ref = ptr;
        ref_counter = new ReferenceCounter();
    }

    SmartPointer(const SmartPointer<T> &other) {
        ref = other.ref;
        ref_counter = other.ref_counter;
        ref_counter->AddReference();
    }

    T& operator*() {
        return *ref;
    }

    T* operator->() {
        return ref;
    }

    SmartPointer<T> & operator=(const SmartPointer<T> &other) {
        if (this != &other) {
            if (ref_counter->RemoveReference() == 0) {
                delete ref;
                delete ref_counter;
            }

            ref = other.ref;
            ref_counter = other.ref_counter;
            ref_counter->AddReference();
        }
        return *this;
    }

    ~SmartPointer() {
        if (ref_counter->RemoveReference() == 0) {
            delete ref;
            delete ref_counter;
        }
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
