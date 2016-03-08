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
    ListNode* swapPairs(ListNode* head) {
        ListNode *first, *second, *after;
        first = head;
        after = NULL;

        while(first && first->next) {
            second = first->next;
            first->next = second->next;
            second->next = first;

            after == NULL ? head = second : after->next = second;

            after = first;
            first = first->next;
        }

        return head;
    }
};


int main() {
    ListNode *head = new ListNode(1);
    ListNode *p = head;
    for(int i=2; i<6; ++i) {
        p->next = new ListNode(i);
        p = p->next;
    }

    p = head;
    while(p) {
        cout<<p->val<<" ";
        p = p->next;
    }
    cout<<endl;

    Solution sol;
    head = sol.swapPairs(head);

    while(head) {
        cout<<head->val<<" ";
        head = head->next;
    }
    cout<<endl;
}