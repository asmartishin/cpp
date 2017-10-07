#include <iostream>
#include <initializer_list>

using namespace std;


template <typename T>
class Linkedlist {
private:
    struct Node {
        T data;
        Node *next;

        Node(T data) {
            this->data = data;
            next = nullptr;
        }
    };
    Node *head;

public:
    Linkedlist() {
        head = nullptr;
    }

    Linkedlist(initializer_list<T> args) {
        head = nullptr;

    	for (auto it = args.begin(); it != args.end(); ++it)
            this->push(*it);
    }

    void push(T data) {
        Node *new_node = new Node(data);

        if (!head)
            head = new_node;
        else {
            Node *current_node = head;
            while (current_node->next)
                current_node = current_node->next;
            current_node->next = new_node;
        }
    }

    T pop() {
        if (!head)
            throw out_of_range("Bad index");

        Node *old_head_node = head;
        T data = old_head_node->data;

        if (old_head_node->next)
            head = old_head_node->next;
        else
            head = nullptr;

        delete old_head_node;
        return data;
    }

    void print() {
        Node *current_node = head;

        while (current_node) {
            cout << current_node->data << ' ';
            current_node = current_node->next;
        }
        cout << endl;
    }

    void reverse() {
        Node *previous_node = nullptr;
        Node *current_node = head;
        Node *next_node;

        while (current_node != nullptr) {
            next_node=current_node->next;
            current_node->next = previous_node;

            previous_node = current_node;
            current_node = next_node;
        }

        head = previous_node;
    }

    ~Linkedlist() {
        while (head != nullptr) {
            Node *old_head_node = head;
            head = head->next;
            delete old_head_node;
        }
    }
};

int main() {
    Linkedlist<double> q = {1,2,3,4};

    q.print();
    q.reverse();
    q.print();
}
