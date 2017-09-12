#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <map>

using namespace std;


template<typename T>
class Heap {
    vector<T> heap;

    int getLeftChild(int parent) {
        return 2 * parent + 1;
    }

    int getRightChild(int parent) {
        return 2 * parent + 2;
    }

    int getParent(int child) {
        if (child % 2 == 0) {
            return child / 2 - 1;
        } else {
            return child / 2;
        }
    }

    void heapifyDown(int node) {
        int left = getLeftChild(node);
        int right = getRightChild(node);

	int smallest = [](const vector<pair<int, int> > &v) {
            return min_element(v.begin(), v.end())->second;
        }({
            {heap[node], node},
            {left < size() ? heap[left]: INT_MAX, left},
            {right < size() ? heap[right]: INT_MAX, right}
        });

        if (smallest != node) {
            swap(heap[node], heap[smallest]);
            heapifyDown(smallest);
        }
    }

    void heapifyUp(int node) {
        int parent = getParent(node);

        if (node && heap[parent] > heap[node]) {
            swap(heap[node], heap[parent]);
            heapifyUp(parent);
        }
    }
public:
    Heap() {}

    unsigned int size() {
        return heap.size();
    }

    bool empty() {
        return size() == 0;
    }

    void push(T value) {
        heap.push_back(value);
        heapifyUp(size() - 1);
    }

    void pop() {
        try {
            if (empty()) {
                throw out_of_range("Bad index");
            }

            heap[0] = heap.back();
            heap.pop_back();
            heapifyDown(0);
        } catch (const out_of_range& e) {
            cout << e.what() << endl;
            throw;
        }
    }

    int top() {
        try {
            if (empty()) {
                throw out_of_range("Bad index");
            }
            return heap[0];
        } catch (const out_of_range& e) {
            cout << e.what() << endl;
            throw;
        }
    }

    void print() {
        for (size_t i = 0; i < size(); ++i) {
            cout << heap[i] << ' ';
        }
        cout << endl;
    }
};


int main() {
    Heap<int> h;

    int n, k, v;

    cin >> n >> k;

    for (size_t i = 0; i < n; ++i) {
        cin >> v;
        h.push(v);
    }

    h.print();

    for (int i = 0; i < k - 1; ++i) {
        h.pop();
    }

    cout << h.top() << endl;
    return 0;
}
