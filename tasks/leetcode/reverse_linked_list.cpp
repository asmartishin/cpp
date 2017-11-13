#include <iostream>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL) {}

    void print() {
        ListNode *current = this;
        while (current) {
            cout << current->val << endl;
            current = current->next;
        }
    }
};


ListNode* reverseList(ListNode *head) {
    ListNode *previous = NULL;
    ListNode *current = head;
    ListNode *next = NULL;

    while (current) {
        next = current->next;
        current->next = previous;
        previous = current;
        current = next;
    }

    return previous;
}


int main() {
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);

    head = reverseList(head);

    head->print();

    return 0;
}
