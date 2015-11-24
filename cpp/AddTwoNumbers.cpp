#include <iostream>

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head, *p;
        head = p = NULL;

        int m, n;
        m = n = 0;
        while(l1 && l2) {
            m = l1->val + l2->val + n;
            n = m / 10;
            m = m % 10;

            if(head == NULL) {
                head = p = new ListNode(m);
            } else {
                p->next = new ListNode(m);
                p = p->next;
            }

            l1 = l1->next;
            l2 = l2->next;
        }

        if(l1 || l2) {
            ListNode* l3 = l1 ? l1 : l2;

            while(l3) {
                m = l3->val + n;
                n = m / 10;
                m = m % 10;

                p->next = new ListNode(m);
                p = p->next;

                l3 = l3->next;
            }
        }

        if(n != 0) {
            p->next = new ListNode(n);
        }

        return head;
    }
};

int main() {
    return 0;
}