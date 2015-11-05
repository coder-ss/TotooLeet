#include <iostream>

using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    void deleteNode(ListNode* node) {
        if(node == NULL || node->next == NULL) {
            return;
        }

        ListNode *tmp = node->next;

        node->val = tmp->val;
        node->next = tmp->next;

        delete tmp;
    }
};

int main() {
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    //head->next->next->next = new ListNode(4);

    Solution *sol = new Solution;
    sol->deleteNode(head->next->next);

    while(head) {
        cout<<head->val<<" ";
        head = head->next;
    }
    cout<<endl;

    return 0;
}