#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;


template <typename T>
class Treap {
private:
    static const int PRIORITY_POOL = 100;

    struct Node {
        T data;
        int priority;
        shared_ptr<Node> left, right;

        Node() {
            left = right = nullptr;
        }

        Node(T&& data) {
            this->data = move(data);
            priority = rand() % PRIORITY_POOL;
            left = right = nullptr;
        }
    };

    shared_ptr<Node> root;

    shared_ptr<Node> rightRotate(shared_ptr<Node> &node) {
        shared_ptr<Node> left_child = move(node->left);
        node->left = move(left_child->right);
        left_child->right = node;
        return left_child;
    }

    shared_ptr<Node> leftRotate(shared_ptr<Node> &node) {
        shared_ptr<Node> right_child = node->right;
        node->right = right_child->left;
        right_child->left = node;
        return right_child;
    }

    shared_ptr<Node> insert(shared_ptr<Node> &node, T data) {
        if (!node)
            return make_shared<Node>(move(data));

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

    shared_ptr<Node> erase(shared_ptr<Node> &node, T data) {
        if (!node)
            return move(node);

        if (data < node->data)
            node->left = erase(node->left, data);
        else if (data > node->data)
            node->right = erase(node->right, data);
        else if (!node->left) {
            node = node->right;
        } else if (!node->right) {
            node = node->left;
        } else if (node->left->priority < node->right->priority){
            node = leftRotate(node);
            node->left = erase(node->left, data);
        } else {
            node = rightRotate(node);
            node->right = erase(node->right, data);
        }

        return node;
    }

    shared_ptr<Node> find(shared_ptr<Node> &node, T data) {
        if (!node)
            return nullptr;
        else if (data < node->data)
            return find(node->left, data);
        else if (data > node->data)
            return find(node->right, data);

        return node;
    }

    void inorder(shared_ptr<Node> &node, vector<pair<T, int> > &nodes) {
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

    ~Treap() {}

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

