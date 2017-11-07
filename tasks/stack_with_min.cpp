#include <iostream>
#include <stack>

using namespace std;


struct MinStack {
    stack<int> s;
    stack<int> ms;

    void push(int x) {
        s.push(x);

        if (ms.empty() || ms.top() >= x)
            ms.push(x);
    }

    void pop() {
        int x = s.top();
        s.pop();

        if (x == ms.top())
            ms.pop();
    }

    int top() {
        return s.top();
    }

    int min() {
        return ms.top();
    }

    int size() {
        return s.size();
    }
};


int main() {
    MinStack min_stack;

    min_stack.push(2);
    min_stack.push(1);


    cout << min_stack.top() << endl;
    cout << min_stack.min() << endl;

    min_stack.pop();

    cout << min_stack.min() << endl;

    return 0;
}
