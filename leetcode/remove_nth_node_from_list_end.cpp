#include <iostream>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}

    static void print(ListNode *head) {
        ListNode *current_node = head;

        while (current_node != NULL) {
            cout << current_node->val << ' ';
            current_node = current_node->next;
        }
    }
};


ListNode * removeNthFromEnd(ListNode *head, int n) {
    ListNode *first_pointer = head;
    ListNode *second_pointer = head;

    int i = 0;
    while (i < n) {
        second_pointer = second_pointer->next;
        ++i;
    }

    while (second_pointer != NULL) {
        first_pointer = first_pointer->next;
        second_pointer = second_pointer->next;
    }

    if (first_pointer == head) {
        if (first_pointer->next != NULL)
            return first_pointer->next;
        else
            return NULL;
    } else if (first_pointer->next != NULL) {
        first_pointer->val = first_pointer->next->val;
        first_pointer->next = first_pointer->next->next;
    } else {
        second_pointer = head;
        while (second_pointer->next != first_pointer)
            second_pointer = second_pointer->next;
        second_pointer->next = NULL;
    }

    return head;
}


int main() {
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);

    ListNode::print(removeNthFromEnd(head, 3));

    return 0;
}
