#include <iostream>
#include <memory>

using namespace std;


struct Node {
    int data;
    Node *next;
};


class Stack {
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


int main() {
    int n, d;
    Stack s;

    cin >> n;

    for (size_t i = 0; i < n; ++i) {
        cin >> d;
        s.push(d);
    }

    cout << endl;

    s.print();

    return 0;
}
