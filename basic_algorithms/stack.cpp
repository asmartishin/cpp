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

    void show() {
        Node *ptr = top;
        while (ptr != nullptr) {
            cout << ptr->value << endl;
            ptr = ptr->next;
        }
    }
};


int main() {
    Stack s;
    s.push(1);
    s.push(2);
    cout << s.pop() << endl;
    cout << s.pop() << endl;

    return 0;
}
