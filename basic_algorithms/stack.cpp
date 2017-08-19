#include <iostream>
#include <memory>

using namespace std;


struct Node
{
    int value;
    Node *next;
};


class Stack
{
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

    void push(int value) {
        Node *ptr = new Node;
        ptr->value = value;
        ptr->next = nullptr;
        if (top != nullptr) {
            ptr->next=top;
        }
        top = ptr;
    }

    int pop() {
        if (top != nullptr) {
            int value = top->value;
            top = top->next;
            delete top;
            return value;
        } else {
            throw runtime_error("Stack is empty");
        }
    }

    void print() {
        Node *ptr = top;
        while (ptr != nullptr) {
            cout << ptr->value << endl;
            ptr = ptr->next;
        }
    }
};


int main() {
    int n, v;
    Stack s;

    cin >> n;

    for (size_t i = 0; i < n; ++i) {
        cin >> v;
        s.push(v);
    }

    cout << endl;

    s.print();

    return 0;
}
