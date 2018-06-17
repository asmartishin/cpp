#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <limits>
#include <cassert>
#include <fstream>
#include <array>

#define endl '\n'

using std::vector;
using std::pair;
using std::cout;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x)
        : val(x)
        , next(nullptr)
    {}
};

struct CompareListNodes {
    inline size_t operator()(const ListNode *lhs, const ListNode *rhs) const {
        return lhs->val > rhs->val;
    }
};

class Solution {
public:
    static ListNode* mergeKLists(vector<ListNode*>& lists) {
        std::priority_queue<ListNode*, vector<ListNode*>, CompareListNodes> pq;

        for (const auto node: lists) {
            if (node != nullptr) {
                pq.push(node);
            }
        }

        ListNode *newlistHead = new ListNode(-1);
        ListNode *newListNode = newlistHead;

        while (!pq.empty()) {
            ListNode *node = pq.top();
            pq.pop();

            if (node->next != nullptr) {
                pq.push(node->next);
            }

            newListNode->next = node;
            newListNode = newListNode->next;
        }

        if (newlistHead == newListNode) {
            return nullptr;
        } else {
            return newlistHead->next;
        }
    }
};


void printList(ListNode *head) {
    ListNode *currentNode = head;
    while (currentNode != nullptr) {
        cout << currentNode->val << ' ';
        currentNode = currentNode->next;
    }
}


int main() {
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.precision(10);


    ListNode *listNode1 = new ListNode{1};
    listNode1->next = new ListNode{4};
    listNode1->next->next = new ListNode{5};

    ListNode *listNode2 = new ListNode{1};
    listNode2->next = new ListNode{3};
    listNode2->next->next = new ListNode{4};

    ListNode *listNode3 = new ListNode{2};
    listNode3->next = new ListNode{6};

    std::vector<ListNode*> lists{
        listNode1,
        listNode2,
        listNode3
    };

    ListNode *newList = Solution::mergeKLists(lists);

    printList(newList);

    return 0;
}
