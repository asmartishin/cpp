#include <iostream>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL) {}
};


int main() {
    ListNode *head = new ListNode{3};
    head->next = new ListNode{2};
    head->next->next = new ListNode{1};

    ListNode *delete_node = head->next;

    delete_node->val = delete_node->next->val;
    delete_node->next = delete_node->next->next;

    ListNode *current = head;

    while (current != NULL) {
        cout << current->val << endl;
        current = current->next;
    }

    return 0;
}
