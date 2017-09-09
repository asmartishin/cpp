#include <iostream>

using namespace std;

template <typename T>
struct Node {
    T data;
    Node<T> *next;
};


template <typename T>
class Queue {
public:
    Node<T> *front, *back;
    Queue() {front = nullptr; back = nullptr;}

    void push_back(T data) {
        Node<T> *ptr = new Node<T>;
        ptr->data = data;
        ptr->next = nullptr;

        if (front == nullptr) {
            front = ptr;
            back = ptr;
        } else {
            back->next = ptr;
            back=ptr;
        }
    }

    T pop_back() {
        if (front == nullptr) {
            throw runtime_error("Queue is empty");
        }

        Node<T> *ptr = front;
        T data = ptr->data;

        if (front == back) {
            front = nullptr;
            back = nullptr;
        } else {
            front = front->next;
        }

        delete ptr;
        return data;
    }

    void print() {
        Node<T> *ptr = front;

        while (ptr) {
            cout << ptr->data << ' ';
            ptr = ptr->next;
        }
        cout << endl;
    }
    ~Queue() {
        while (front != nullptr) {
            Node<T> *ptr = front;
            front = front->next;
            delete ptr;
        }
        back = nullptr;
    }
};


int main() {
    int n;
    double d;
    Queue<double> q;

    cin >> n;

    for (size_t i = 0; i < n; ++i) {
        cin >> d;
        q.push_back(d);
    }

    q.print();

    for (size_t i = 0; i < n; ++i) {
        cout << q.pop_back() << endl;
    }
}
