#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;


template <typename T>
class Treap {
private:
    struct Node {
        T data;
        int priority;
        Node *left, *right;

        Node() {
            left = right = nullptr;
        }

        Node(T data) {
            this->data = data;
            priority = rand() % 100;
            left = right = nullptr;
        }
    };

    Node *root;

    Node* clear(Node *node) {
        if (!node) {
            return nullptr;
        }

        clear(node->left);
        clear(node->right);
        return nullptr;
    }

    Node* rightRotate(Node *node) {
        Node *left_child = node->left;
        node->left = left_child->right;
        left_child->right = node;
        return left_child;
    }

    Node* leftRotate(Node *node) {
        Node *right_child = node->right;
        node->right = right_child->left;
        right_child->left = node;
        return right_child;
    }

    Node* insert(Node *node, T data) {
        if (!node)
            return new Node(data);

        if (data < node->data) {
            node->left = insert(node->left, data);

            if (node->left->priority > node->priority)
                node = rightRotate(node);
        } else {
            node->right = insert(node->right, data);

            if (node->right->priority > node->priority)
                node = leftRotate(node);
        }

        return node;
    }

    Node* erase(Node *node, T data) {
        if (!node)
            return node;

        if (data < node->data)
            node->left = erase(node->left, data);
        else if (data > node->data)
            node->right = erase(node->right, data);
        else if (!node->left) {
            Node *right_child = node->right;
            delete(node);
            node = right_child;
        } else if (!node->right) {
            Node *left_child = node->left;
            delete(node);
            node = left_child;
        } else if (node->left->priority < node->right->priority){
            node = leftRotate(node);
            node->left = erase(node->left, data);
        } else {
            node = rightRotate(node);
            node->right = erase(node->right, data);
        }

        return node;
    }

    Node* find(Node *node, T data) {
        if (!node)
            return nullptr;
        else if (data < node->data)
            return find(node->left, data);
        else if (data > node->data)
            return find(node->right, data);

        return node;
    }

    void inorder(Node *node, vector<pair<T, int> > &nodes) {
        if (node) {
            inorder(node->left, nodes);
            nodes.push_back(make_pair(node->data, node->priority));
            inorder(node->right, nodes);
        }
    }

public:
    Treap() {
        root = nullptr;
    }

    ~Treap() {
        root = clear(root);
    }

    void insert(T data) {
        root = insert(root, data);
    }

    void erase(T data) {
        root = erase(root, data);
    }

    bool find(T data) {
        if (find(root, data) != nullptr) {
            return true;
        }
        return false;
    }

    void print() {
        vector<pair<T, int> > nodes;
        inorder(root, nodes);

        for (size_t i = 0; i < nodes.size(); ++i) {
            cout << "{" << nodes[i].first << ", " << nodes[i].second  << "} ";
        }

        cout << endl;
    }
};


int main() {
    Treap<int> t;

    t.insert(1);
    t.insert(3);
    t.insert(2);
    t.insert(4);
    t.insert(5);
    t.insert(7);
    t.insert(6);

    t.erase(6);

    t.print();

    cout << t.find(1) << endl;
    return 0;
}

